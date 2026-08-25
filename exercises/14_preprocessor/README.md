# Preprocessor

C23 fills in several preprocessor holes:

```c
#if defined(A)
#elifdef B          /* #elif defined(B) */
#elifndef C         /* #elif !defined(C) */
#endif

#if __has_include(<stdbit.h>)
#include <stdbit.h>
#endif

unsigned char blob[] = {
#embed "mascot.txt"
};

#define LOG(fmt, ...) printf(fmt __VA_OPT__(,) __VA_ARGS__)
```

`#embed` expands to a comma-separated list of byte values from a file
(relative to the source file). GCC 15 and Clang 19 implement it.

## Reading

- https://en.cppreference.com/w/c/preprocessor/conditional
- https://en.cppreference.com/w/c/preprocessor/embed
- https://en.cppreference.com/w/c/preprocessor/include
- https://en.cppreference.com/w/c/preprocessor/replace
