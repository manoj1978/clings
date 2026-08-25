# `<stdckdint.h>`

Checked integer arithmetic. The `ckd_*` macros store the mathematical
result in `*result` and return `true` if it does **not** fit in that
object's type (overflow / wrap that would have been silent).

```c
#include <stdckdint.h>

int r;
bool overflow = ckd_add(&r, INT_MAX, 1);  /* overflow == true */
bool ok       = ckd_mul(&r, 6, 7);        /* ok == false, r == 42 */
```

There is `ckd_add`, `ckd_sub`, and `ckd_mul`.

## Reading

- https://en.cppreference.com/w/c/header/stdckdint
