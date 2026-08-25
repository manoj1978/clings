# auto

C23 reuses `auto` for type inference. With an initializer and no type,
the compiler takes the type of the initializer:

```c
auto n = 42;       /* int */
auto x = 3.14;     /* double */
auto p = nullptr;  /* nullptr_t */
```

There must be an initializer. `auto n;` is invalid. C23 does not infer
function return types or parameter types.

`auto int n = 1;` still means the old storage-class `auto` (almost never
what you want).

## Reading

- https://en.cppreference.com/w/c/keyword/auto
