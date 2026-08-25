# Literals

Two readability upgrades, both borrowed from C++:

```c
int mask = 0b1111'0000;
long population = 1'234'567;
```

- `0b` / `0B` starts a binary integer literal.
- `'` between digits is a digit separator. It is ignored.

They combine: `0b1010'0001`, `0xFF'EE`.

## Reading

- https://en.cppreference.com/w/c/language/integer_constant
