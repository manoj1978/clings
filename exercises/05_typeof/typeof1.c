// I AM NOT DONE
//
// `typeof(expr)` names the type of that expression. Use it to declare
// `copy` with the same type as `seed` (a `double`).

#include <assert.h>

int main(void)
{
    double seed = 1.5;
    ??? copy = seed * 2;

    static_assert(_Generic(copy, double: 1, default: 0));
    assert(copy == 3.0);
    return 0;
}
