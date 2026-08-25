# constexpr

C23 `constexpr` on an *object* makes it a compile-time constant:

```c
constexpr int n = 4;
int a[n];              /* not a VLA */
static_assert(n == 4); /* ok */
```

A C `const int n = 4;` is **not** an integer constant expression. That is
the most common surprise for people coming from C++.

C23 `constexpr` is only for objects, not for functions.

## Reading

- https://en.cppreference.com/w/c/language/constexpr
