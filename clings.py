#!/usr/bin/env python3
"""clings — small exercises that teach C23, in the spirit of rustlings."""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent
EXERCISES_FILE = ROOT / "exercises.json"
BUILD_DIR = ROOT / ".clings-build"
DONE_MARKER = "I AM NOT DONE"
DONE_LINE = f"// {DONE_MARKER}"
STDLIB = ["-std=c23", "-Wall", "-Wextra"]
RUN_TIMEOUT = 5

BANNER = r"""
      _ _
  ___| (_)_ __   __ _ ___
 / __| | | '_ \ / _` / __|
| (__| | | | | | (_| \__ \
 \___|_|_|_| |_|\__, |___/
                |___/      C23
"""

FINAL = r"""
You made it. C23 is no longer a list of papers — it's a dialect you can write.

What you picked up:
  keywords     bool true false nullptr constexpr auto typeof alignas
  literals     0b1010  1'000'000  wb/uwb
  attributes   [[nodiscard]] [[fallthrough]] [[maybe_unused]] [[deprecated]]
  library      <stdbit.h> <stdckdint.h> strdup unreachable #embed

Keep going: read the C23 cppreference pages, then rewrite a small C17
program in C23 and see how much ceremony you can delete.
"""

if sys.stdout.isatty():
    BOLD = "\033[1m"
    DIM = "\033[2m"
    RED = "\033[31m"
    GREEN = "\033[32m"
    YELLOW = "\033[33m"
    CYAN = "\033[36m"
    RESET = "\033[0m"
else:
    BOLD = DIM = RED = GREEN = YELLOW = CYAN = RESET = ""


def c(style: str, text: str) -> str:
    return f"{style}{text}{RESET}"


@dataclass
class Exercise:
    name: str
    path: str
    hint: str
    cflags: list[str]
    passing: bool

    @property
    def source(self) -> Path:
        return ROOT / self.path

    @property
    def solution(self) -> Path:
        return ROOT / "solutions" / Path(self.path).relative_to("exercises")


def load_exercises() -> list[Exercise]:
    data = json.loads(EXERCISES_FILE.read_text())
    out = []
    for item in data["exercises"]:
        out.append(
            Exercise(
                name=item["name"],
                path=item["path"],
                hint=item["hint"].strip("\n"),
                cflags=item.get("cflags", []),
                passing=item.get("passing", False),
            )
        )
    return out


def find_compiler() -> str:
    candidates = []
    if os.environ.get("CC"):
        candidates.append(os.environ["CC"])
    candidates.extend(["gcc", "clang", "cc"])
    for cc in candidates:
        path = shutil.which(cc)
        if path:
            return path
    sys.exit(
        c(RED, "error:")
        + " no C compiler found. Install GCC 14+ or Clang 19+, or set CC."
    )


def require_c23(cc: str) -> None:
    prog = b"int main(void){static_assert(__STDC_VERSION__>=202311L);}\n"
    with tempfile.TemporaryDirectory() as tmp:
        out = Path(tmp) / "probe"
        result = subprocess.run(
            [cc, "-std=c23", "-x", "c", "-", "-o", str(out)],
            input=prog,
            capture_output=True,
        )
    if result.returncode != 0:
        err = result.stderr.decode("utf-8", "replace")
        sys.exit(
            c(RED, "error:")
            + f" {cc} does not compile C23 (__STDC_VERSION__ >= 202311L).\n"
            + "Need GCC 14+ (GCC 15 for #embed) or Clang 19+.\n"
            + err
        )


def compile_file(
    cc: str, source: Path, extra: list[str], binary: Path
) -> subprocess.CompletedProcess:
    binary.parent.mkdir(parents=True, exist_ok=True)
    cmd = [cc, *STDLIB, *extra, "-o", str(binary), str(source)]
    return subprocess.run(cmd, capture_output=True, cwd=ROOT)


def run_binary(binary: Path) -> subprocess.CompletedProcess:
    return subprocess.run(
        [str(binary)],
        capture_output=True,
        cwd=ROOT,
        timeout=RUN_TIMEOUT,
    )


@dataclass
class Result:
    ok: bool
    compile: subprocess.CompletedProcess | None = None
    run: subprocess.CompletedProcess | None = None
    still_marked: bool = False
    message: str = ""


def has_not_done(source: Path) -> bool:
    try:
        for line in source.read_text().splitlines():
            if line.strip() == DONE_LINE:
                return True
        return False
    except OSError:
        return True


def verify(cc: str, ex: Exercise, source: Path | None = None) -> Result:
    src = source or ex.source
    if not src.exists():
        return Result(False, message=f"missing file: {src}")

    binary = BUILD_DIR / ex.name
    compiled = compile_file(cc, src, ex.cflags, binary)
    if compiled.returncode != 0:
        return Result(False, compile=compiled)

    try:
        ran = run_binary(binary)
    except subprocess.TimeoutExpired:
        return Result(
            False,
            compile=compiled,
            message=f"program timed out after {RUN_TIMEOUT}s",
        )
    if ran.returncode != 0:
        return Result(False, compile=compiled, run=ran)

    if has_not_done(src):
        return Result(True, compile=compiled, run=ran, still_marked=True)
    return Result(True, compile=compiled, run=ran)


def decode(proc: subprocess.CompletedProcess | None) -> str:
    if proc is None:
        return ""
    out = []
    if proc.stdout:
        out.append(proc.stdout.decode("utf-8", "replace"))
    if proc.stderr:
        out.append(proc.stderr.decode("utf-8", "replace"))
    return "".join(out).rstrip()


def print_result(ex: Exercise, result: Result) -> None:
    print(c(BOLD, f"Exercise: {ex.name}") + f"  {c(DIM, ex.path)}")
    print()
    if result.compile is not None and result.compile.returncode != 0:
        print(c(RED, "Compile failed"))
        print()
        print(decode(result.compile))
        return
    if result.message:
        print(c(RED, result.message))
        if result.compile:
            text = decode(result.compile)
            if text:
                print(text)
        return
    if result.run is not None and result.run.returncode != 0:
        print(c(RED, f"Program crashed or returned {result.run.returncode}"))
        print()
        print(decode(result.run))
        return
    output = decode(result.run)
    if output:
        print(c(DIM, "Output:"))
        print(output)
        print()
    if result.still_marked:
        print(c(GREEN, "It compiles and runs."))
        print(
            "Remove the "
            + c(YELLOW, DONE_LINE)
            + " comment at the top of the file to continue."
        )
        return
    print(c(GREEN, f"✓  {ex.name} done"))


def progress_bar(done: int, total: int, width: int = 28) -> str:
    filled = 0 if total == 0 else int(width * done / total)
    bar = "█" * filled + "░" * (width - filled)
    return f"[{bar}] {done}/{total}"


_ok_mtime: dict[str, float] = {}


def first_outstanding(cc: str, exercises: list[Exercise]) -> Exercise | None:
    for ex in exercises:
        if not ex.source.exists() or has_not_done(ex.source):
            return ex
        mtime = ex.source.stat().st_mtime
        key = str(ex.source)
        if _ok_mtime.get(key) == mtime:
            continue
        result = verify(cc, ex)
        if not result.ok or result.still_marked:
            return ex
        _ok_mtime[key] = mtime
    return None


def status_map(exercises: list[Exercise]) -> dict[str, str]:
    # Fast path: I AM NOT DONE means pending. No marker means we treat it as
    # done for listing; watch/verify still compile to be sure.
    out = {}
    for ex in exercises:
        if not ex.source.exists():
            out[ex.name] = "missing"
        elif has_not_done(ex.source):
            out[ex.name] = "pending"
        else:
            out[ex.name] = "done"
    return out


def cmd_list(exercises: list[Exercise]) -> int:
    states = status_map(exercises)
    done = sum(1 for s in states.values() if s == "done")
    print(c(CYAN, BANNER))
    print(progress_bar(done, len(exercises)))
    print()
    name_w = max(len(ex.name) for ex in exercises)
    for ex in exercises:
        state = states[ex.name]
        if state == "done":
            tag = c(GREEN, "DONE   ")
        elif state == "missing":
            tag = c(RED, "MISSING")
        else:
            tag = c(YELLOW, "TODO   ")
        print(f"  {tag}  {ex.name:<{name_w}}  {c(DIM, ex.path)}")
    print()
    return 0


def cmd_hint(exercises: list[Exercise], name: str | None, cc: str) -> int:
    if name:
        ex = lookup(exercises, name)
    else:
        ex = first_outstanding(cc, exercises)
        if ex is None:
            print("No pending exercise. You are done.")
            return 0
    print(c(BOLD, f"Hint for {ex.name}"))
    print()
    print(ex.hint)
    print()
    return 0


def lookup(exercises: list[Exercise], name: str) -> Exercise:
    for ex in exercises:
        if ex.name == name or ex.path.endswith(name) or Path(ex.path).stem == name:
            return ex
    sys.exit(c(RED, "error:") + f" unknown exercise {name!r}. Try `clings list`.")


def cmd_run(cc: str, exercises: list[Exercise], name: str | None) -> int:
    if name:
        ex = lookup(exercises, name)
    else:
        ex = first_outstanding(cc, exercises)
        if ex is None:
            print(c(GREEN, FINAL))
            return 0
    result = verify(cc, ex)
    print_result(ex, result)
    if result.ok and not result.still_marked:
        return 0
    print()
    print(c(DIM, "hint:") + f"  {Path(sys.argv[0]).name} hint {ex.name}")
    return 1


def cmd_watch(cc: str, exercises: list[Exercise]) -> int:
    print(c(CYAN, BANNER))
    print("Watch mode. Edit the current exercise; it re-runs on save.")
    print(c(DIM, "keys:  r rerun   h hint   l list   q quit"))
    print()

    last_mtime: float | None = None
    current_name: str | None = None

    while True:
        states = status_map(exercises)
        done = sum(1 for s in states.values() if s == "done")
        ex = first_outstanding(cc, exercises)
        if ex is None:
            print()
            print(progress_bar(len(exercises), len(exercises)))
            print(c(GREEN, FINAL))
            return 0

        mtime = ex.source.stat().st_mtime if ex.source.exists() else 0.0
        if ex.name != current_name or mtime != last_mtime:
            current_name = ex.name
            last_mtime = mtime
            print()
            print(c(CYAN, "─" * 60))
            print(progress_bar(done, len(exercises)))
            print()
            result = verify(cc, ex)
            print_result(ex, result)
            if result.ok and not result.still_marked:
                # Advance immediately on the next loop iteration.
                last_mtime = None
                current_name = None
                time.sleep(0.4)
                continue
            print()
            print(c(DIM, "waiting for changes…  (h hint, r rerun, l list, q quit)"))

        key = poll_key(0.4)
        if key in {"q", "\x03"}:
            print("bye")
            return 0
        if key == "h":
            print()
            print(c(YELLOW, f"Hint for {ex.name}:"))
            print(ex.hint)
            print()
        elif key == "l":
            print()
            cmd_list(exercises)
        elif key == "r":
            last_mtime = None


def poll_key(timeout: float) -> str | None:
    if not sys.stdin.isatty():
        time.sleep(timeout)
        return None
    try:
        import select
        import termios
        import tty
    except ImportError:
        time.sleep(timeout)
        return None

    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    try:
        tty.setcbreak(fd)
        ready, _, _ = select.select([sys.stdin], [], [], timeout)
        if ready:
            ch = sys.stdin.read(1)
            if ch == "\x1b":
                # Drain the rest of an escape sequence.
                while select.select([sys.stdin], [], [], 0.0)[0]:
                    sys.stdin.read(1)
                return None
            return ch.lower()
    except termios.error:
        time.sleep(timeout)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
    return None


def write_temp_sibling(source: Path, text: str) -> Path:
    tmp = source.with_name(f".{source.stem}.clings-tmp.c")
    tmp.write_text(text)
    return tmp


def cmd_check(cc: str, exercises: list[Exercise]) -> int:
    """Developer check: solutions pass, broken exercises fail."""
    failures = 0
    print(c(BOLD, "Checking solutions"))
    for ex in exercises:
        sol = ex.solution
        if not sol.exists():
            print(c(RED, f"  missing solution {sol}"))
            failures += 1
            continue
        result = verify(cc, ex, source=sol)
        if not result.ok or result.still_marked:
            print(c(RED, f"  solution {ex.name} failed"))
            print_result(ex, result)
            failures += 1
        else:
            print(c(GREEN, f"  ✓ {ex.name}"))

    print()
    print(c(BOLD, "Checking that unsolved exercises still fail"))
    for ex in exercises:
        text = "\n".join(
            line
            for line in ex.source.read_text().splitlines()
            if line.strip() != DONE_LINE
        )
        if text and not text.endswith("\n"):
            text += "\n"
        tmp = write_temp_sibling(ex.source, text)
        try:
            result = verify(cc, ex, source=tmp)
        finally:
            tmp.unlink(missing_ok=True)
        should_pass = ex.passing
        did_pass = result.ok and not result.still_marked
        if should_pass and not did_pass:
            print(c(RED, f"  {ex.name} is marked passing but does not compile/run"))
            print_result(ex, result)
            failures += 1
        elif not should_pass and did_pass:
            print(
                c(
                    RED,
                    f"  {ex.name} passes before it is solved — it needs a real error",
                )
            )
            failures += 1
        else:
            state = "already-correct" if should_pass else "still-broken"
            print(c(GREEN, f"  ✓ {ex.name}") + c(DIM, f"  ({state})"))

    print()
    if failures:
        print(c(RED, f"{failures} check(s) failed"))
        return 1
    print(c(GREEN, "all checks passed"))
    return 0


def cmd_verify(cc: str, exercises: list[Exercise]) -> int:
    failed = 0
    for ex in exercises:
        result = verify(cc, ex)
        if result.ok and not result.still_marked:
            print(c(GREEN, f"✓ {ex.name}"))
        else:
            print(c(YELLOW, f"✗ {ex.name}"))
            print_result(ex, result)
            failed += 1
            break
    if failed == 0:
        print(c(GREEN, FINAL))
        return 0
    return 1


def cmd_reset(exercises: list[Exercise]) -> int:
    print(
        "Reset is you. Exercises live in "
        + c(BOLD, "exercises/")
        + " — restore them from git:\n"
        "  git checkout -- exercises\n"
        "Or copy a single file back from "
        + c(BOLD, "solutions/")
        + " if you only want a peek."
    )
    pending = sum(1 for ex in exercises if has_not_done(ex.source))
    print(f"{pending}/{len(exercises)} still have `// {DONE_MARKER}`.")
    return 0


def build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="clings",
        description="Small exercises to get you used to reading and writing C23.",
    )
    sub = p.add_subparsers(dest="cmd")
    sub.add_parser("watch", help="rerun the current exercise on save (default)")
    run = sub.add_parser("run", help="compile and run one exercise")
    run.add_argument("name", nargs="?", help="exercise name (default: current)")
    hint = sub.add_parser("hint", help="print a hint for an exercise")
    hint.add_argument("name", nargs="?", help="exercise name (default: current)")
    sub.add_parser("list", help="list exercises and progress")
    sub.add_parser("verify", help="run exercises in order until one fails")
    sub.add_parser("check", help="check solutions and that unsolved files still fail")
    sub.add_parser("reset", help="how to restore exercise files")
    return p


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    cmd = args.cmd or "watch"
    exercises = load_exercises()
    if cmd == "list":
        return cmd_list(exercises)
    if cmd == "reset":
        return cmd_reset(exercises)

    cc = find_compiler()
    require_c23(cc)

    if cmd == "watch":
        return cmd_watch(cc, exercises)
    if cmd == "run":
        return cmd_run(cc, exercises, args.name)
    if cmd == "hint":
        return cmd_hint(exercises, args.name, cc)
    if cmd == "verify":
        return cmd_verify(cc, exercises)
    if cmd == "check":
        return cmd_check(cc, exercises)
    parser.error(f"unknown command {cmd}")
    return 2


if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        print("\nbye")
        sys.exit(130)
