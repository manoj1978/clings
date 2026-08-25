# clings

Small exercises to get you used to reading and writing **C23**.

Inspired by [rustlings](https://github.com/rust-lang/rustlings). Most files
do not compile (or do not run correctly) until you fix them. The point is to
read the compiler diagnostics, then write the C23 spelling of the idea.

```
      _ _
  ___| (_)_ __   __ _ ___
 / __| | | '_ \ / _` / __|
| (__| | | | | | (_| \__ \
 \___|_|_|_| |_|\__, |___/
                |___/      C23
```

## Requirements

- Python 3.9+
- A C23 compiler:
  - **GCC 14+** (GCC 15 recommended — it is C23-by-default and supports `#embed`)
  - **Clang 19+** for `#embed` / `constexpr` (Clang 18 covers most earlier topics)

Confirm you are actually in C23:

```bash
cc -std=c23 -dM -E -x c /dev/null | grep STDC_VERSION
# expect 202311
```

## Quick start

```bash
git clone <this-repo> clings
cd clings
python3 clings.py
```

That starts **watch mode**. It compiles the first unfinished exercise, prints
the compiler output, and re-runs when you save the file.

Each exercise starts with:

```c
// I AM NOT DONE
```

When the file compiles, runs, **and** that comment is gone, clings advances.

## Commands

| Command | What it does |
| --- | --- |
| `python3 clings.py` | Watch mode (default) |
| `python3 clings.py run [name]` | Compile and run one exercise |
| `python3 clings.py hint [name]` | Print a hint |
| `python3 clings.py list` | Progress list |
| `python3 clings.py verify` | Run every exercise in order until one fails |
| `python3 clings.py check` | Developer check: solutions pass, unsolved files fail |

In watch mode, with a TTY:

- `r` rerun
- `h` hint
- `l` list
- `q` quit

Set `CC` if you do not want the default (`gcc`, then `clang`, then `cc`):

```bash
CC=gcc python3 clings.py
```

## What you will learn

C23 (ISO/IEC 9899:2024) is the current C standard. These exercises assume you
already know some C (types, functions, pointers, the preprocessor) and teach
the **new dialect**, not C from zero.

| Topic | Directory | C23 ideas |
| --- | --- | --- |
| Intro | `00_intro` | `__STDC_VERSION__ == 202311L` |
| Booleans | `01_bool` | `bool` / `true` / `false` as keywords |
| Null | `02_nullptr` | `nullptr`, `nullptr_t` |
| Literals | `03_literals` | `0b1010`, digit separators `'` |
| `auto` | `04_auto` | type inference from an initializer |
| `typeof` | `05_typeof` | `typeof`, `typeof_unqual` |
| `constexpr` | `06_constexpr` | compile-time objects vs `const` |
| Attributes | `07_attributes` | `[[nodiscard]]`, `[[fallthrough]]`, … |
| Init | `08_init` | empty initializer `= {}` |
| Functions | `09_functions` | unnamed parameters, `foo(...)` |
| Enums | `10_enums` | fixed underlying type |
| `_BitInt` | `11_bitint` | bit-precise integers, `wb` / `uwb` |
| Align | `12_align` | `alignas` / `alignof` |
| Labels | `13_labels` | label followed by a declaration |
| Preprocessor | `14_preprocessor` | `#elifdef`, `#embed`, `__has_include`, `__VA_OPT__` |
| `<stdbit.h>` | `15_stdbit` | popcount, bit floor/ceil |
| `<stdckdint.h>` | `16_ckdint` | checked `add` / `mul` |
| Library | `17_library` | `strdup`, `unreachable()` |
| Compound | `18_compound` | storage class on compound literals |
| Quiz | `19_quiz` | mix several features in one file |

Every topic has a `README.md` with a short briefing and links.

## Layout

```
clings.py          runner (Python, stdlib only)
exercises.json     exercise list, hints, extra compiler flags
exercises/         the files you edit
solutions/         working copies, used by `clings.py check`
```

Do not peek at `solutions/` until you are stuck. `hint` exists for a reason.

## Compiling a single file yourself

```bash
gcc -std=c23 -Wall -Wextra exercises/04_auto/auto1.c
```

Some attribute exercises add `-Werror=…` so a warning is a failed exercise.
`clings.py` already passes those flags.

## Restore an exercise

```bash
git checkout -- exercises/04_auto/auto1.c
```

## License

MIT.
