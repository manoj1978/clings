# bool / true / false

In C99, booleans were `_Bool` plus macros in `<stdbool.h>`. C23 makes
`bool`, `true`, and `false` keywords. `<stdbool.h>` is still there for
old code, but you do not need it.

```c
bool ok = true;
if (!ok) {
    return false;
}
```

`true` has type `bool`, not `int`. `_Generic(true, bool: 1, int: 2)` is 1.

## Reading

- https://en.cppreference.com/w/c/keyword/bool
- https://en.cppreference.com/w/c/language/bool_constant
