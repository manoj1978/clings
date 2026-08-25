// `ckd_mul` is the same shape as `ckd_add`. `100000 * 100000` does not
// fit in a 32-bit `int`. Use `ckd_mul` so you get a boolean, not UB.

#include <assert.h>
#include <stdckdint.h>

int main(void)
{
    int r = 0;
    bool overflow = ckd_mul(&r, 100000, 100000);

    assert(overflow == true);

    bool ok = ckd_mul(&r, 6, 7);
    assert(ok == false);
    assert(r == 42);
    return 0;
}
