// C23 empty initializers: `T x = {};` zeroes `x`.
// That works for scalars, arrays, and structs.
//
// Replace the invalid initializer with `{}`.

#include <assert.h>

struct point {
    int x;
    int y;
};

int main(void)
{
    int n = {};
    int a[4] = {};
    struct point p = {};

    assert(n == 0);
    assert(a[0] == 0 && a[3] == 0);
    assert(p.x == 0 && p.y == 0);
    return 0;
}
