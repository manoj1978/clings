# Labels before declarations

C23 lets a label sit in front of a declaration or a closing brace. You no
longer need a dummy `;` after `done:`:

```c
done:
    int n = 1;    /* illegal before C23, fine now */
```

## Reading

- https://en.cppreference.com/w/c/language/statements
