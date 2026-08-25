// Bit-precise suffixes: `wb` for `_BitInt`, `uwb` for `unsigned _BitInt`.
// `0b1111uwb` has type `unsigned _BitInt(4)` — the smallest width that
// holds the value.
//
// Replace the placeholder with an unsigned bit-precise binary literal
// equal to 15.

#include <assert.h>

int main(void)
{
    auto nibble = 0b1111uwb;

    static_assert(_Generic(nibble, unsigned _BitInt(4): 1, default: 0));
    assert(nibble == 15);
    return 0;
}
