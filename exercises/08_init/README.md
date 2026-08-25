# Empty initializers

C23 lets you write `= {}` for any object. It means "zero this":

```c
int n = {};
int a[4] = {};
struct point p = {};
```

Before C23 you needed `= {0}` for aggregates, and scalars had no empty
form. Empty braces work for all of them now.

## Reading

- https://en.cppreference.com/w/c/language/initialization
