# `<stdbit.h>`

Type-generic bit utilities. The width is the width of the *argument's
type*, so prefer `unsigned char` when you want 8-bit examples.

```c
#include <stdbit.h>

unsigned char x = 0x10;          /* 0b00010000 */
stdc_count_ones(x);              /* 1 */
stdc_leading_zeros(x);           /* 3 */
stdc_trailing_zeros(x);          /* 4 */
stdc_has_single_bit(x);          /* true */
stdc_bit_width(x);               /* 5 */
stdc_bit_floor(x);               /* 16 */
stdc_bit_ceil(x);                /* 16 */
```

## Reading

- https://en.cppreference.com/w/c/header/stdbit
