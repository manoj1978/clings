// I AM NOT DONE
//
// `ckd_add(&out, a, b)` writes a+b into `out` and returns true if the
// result does not fit in `out`'s type.
//
// Detect that `INT_MAX + 1` overflows an `int`.

#include <assert.h>
#include <limits.h>
/* TODO: #include <stdckdint.h> */

int main(void)
{
    int r = 0;
    bool overflow = ???; /* ckd_add(&r, INT_MAX, 1) */

    assert(overflow == true);
    (void)r;
    return 0;
}
