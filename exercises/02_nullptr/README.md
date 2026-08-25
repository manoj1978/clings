# nullptr

`NULL` is a macro, usually `0` or `((void *)0)`. C23 adds a typed null
pointer constant:

```c
int *p = nullptr;
nullptr_t np = nullptr;
p = np;          /* ok, any pointer type */
```

`nullptr` has type `nullptr_t` (`<stddef.h>`). `_Generic` can tell it apart
from `NULL`.

## Reading

- https://en.cppreference.com/w/c/language/nullptr
- https://en.cppreference.com/w/c/types/nullptr_t
