// `typeof` keeps qualifiers. `typeof(x)` when `x` is `const int` is
// `const int`, so you cannot assign to it later.
// `typeof_unqual` drops const/volatile/restrict/_Atomic.
//
// `plain` must be a mutable `int`.

#include <assert.h>

int main(void)
{
    const int x = 3;
    typeof(x) still_const = x;
    typeof_unqual(x) plain = x;

    plain = 7;
    assert(plain == 7);
    assert(still_const == 3);
    static_assert(_Generic(&plain, int *: 1, const int *: 0, default: 2));
    static_assert(_Generic(&still_const, const int *: 1, default: 0));
    return 0;
}
