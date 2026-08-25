// I AM NOT DONE
//
// `unsigned _BitInt(3)` has 3 value bits, so arithmetic is modulo 8.
// `7 + 1` wraps to 0. Use 3-bit unsigned values so the wrap is part of
// the type, not a later cast.

#include <assert.h>

int main(void)
{
    unsigned int a = 7;
    unsigned int b = 1;
    auto sum = a + b;

    static_assert(_Generic(sum, unsigned _BitInt(3): 1, default: 0));
    assert(sum == 0);
    return 0;
}
