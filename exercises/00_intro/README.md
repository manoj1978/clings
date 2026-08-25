# Intro

C23 is ISO/IEC 9899:2024. Compilers still need `-std=c23` (GCC 15 uses C23
by default). The version macro is:

```c
__STDC_VERSION__  ==  202311L
```

clings always compiles with `-std=c23 -Wall -Wextra`.

Every exercise starts with `// I AM NOT DONE`. Delete that comment once the
file compiles and does the right thing.

## Reading

- https://en.cppreference.com/w/c/23
- https://en.cppreference.com/w/c/preprocessor/replace (predefined macros)
