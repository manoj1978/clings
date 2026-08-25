# Storage class on compound literals

A compound literal `(T){ ... }` has automatic storage by default, so this
is a dangling pointer:

```c
int *f(void)
{
    return (int[]){1, 2, 3}; /* dies when f returns */
}
```

C23 lets you write a storage-class specifier on the compound literal:

```c
return (static int[]){1, 2, 3};      /* lasts the whole program */
constexpr int *p = (constexpr int[]){1, 2, 3};
```

## Reading

- https://en.cppreference.com/w/c/language/compound_literal
