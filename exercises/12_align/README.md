# alignas / alignof

C11 added `_Alignas` / `_Alignof`. C23 makes `alignas` and `alignof`
keywords. `<stdalign.h>` is still available, but you do not need it.

```c
alignas(32) unsigned char buf[64];
static_assert(alignof(buf) == 32);
```

## Reading

- https://en.cppreference.com/w/c/keyword/alignas
- https://en.cppreference.com/w/c/keyword/alignof
