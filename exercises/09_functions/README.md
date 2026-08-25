# Functions

C23 drops two pieces of K&R baggage and adds two conveniences.

Unnamed parameters — if you do not use an argument, you do not have to
name it:

```c
int callback(void *ctx, int)
{
    (void)ctx;
    return 0;
}
```

Empty parameter lists are now `(void)`. `int f()` means `int f(void)`.

A variadic function no longer needs a named argument before `...`:

```c
int first(...)
{
    va_list ap;
    va_start(ap);     /* one argument, not two */
    int x = va_arg(ap, int);
    va_end(ap);
    return x;
}
```

## Reading

- https://en.cppreference.com/w/c/language/function_definition
- https://en.cppreference.com/w/c/language/variadic
