# Library additions

A few C23 stdlib highlights that show up in real code:

```c
char *copy = strdup(src);     /* <string.h>, free it */
char *p    = strndup(src, n);

#include <stddef.h>
unreachable();                /* this path cannot happen */
```

`unreachable()` is a macro. After it, the compiler may assume the program
does not continue. Use it for exhaustive switches, not as a substitute
for error handling.

## Reading

- https://en.cppreference.com/w/c/string/byte/strdup
- https://en.cppreference.com/w/c/program/unreachable
