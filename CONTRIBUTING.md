# Contributing to clings

Exercises are listed in `exercises.json` and live under `exercises/`. Every
exercise has a matching file under `solutions/`.

## Adding an exercise

1. Create `exercises/<topic>/<name>.c` with `// I AM NOT DONE` at the top.
   The unsolved file must **fail** to compile or run (unless `"passing": true`).
2. Create `solutions/<topic>/<name>.c` — the same program, fixed, no marker.
3. Register it in `exercises.json` (name, path, hint, optional `cflags`).
4. Add a line to the topic `README.md` if you introduced a new directory.
5. Run `python3 clings.py check`.

## Exercise style

- Teach one C23 idea per file.
- Comments at the top explain the rule; they do not paste the answer.
- Prefer a real compile error over a comment that says "TODO: change this
  so it still compiles".
- Use `static_assert`, `_Generic`, and `assert` to lock down the type or
  value you want.
- Keep the program short enough to read in one screen.

## Running the suite

```bash
python3 clings.py check
```

That compiles every solution (they must run with exit 0) and confirms that
each unsolved exercise still fails after `// I AM NOT DONE` is stripped.
