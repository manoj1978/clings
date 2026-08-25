# typeof

`typeof(expr)` is the type of `expr`. `typeof_unqual(expr)` is the same
type with `const`, `volatile`, `restrict`, and `_Atomic` stripped.

```c
int x;
typeof(x) y = x;              /* int */
const int c = 1;
typeof(c) still_const = c;    /* const int */
typeof_unqual(c) plain = c;   /* int */
```

Unlike `auto`, `typeof` works without an initializer and works in macros:

```c
#define SWAP(a, b) do { typeof(a) tmp = (a); (a) = (b); (b) = tmp; } while (0)
```

## Reading

- https://en.cppreference.com/w/c/language/typeof
