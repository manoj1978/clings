// `unsigned _BitInt(8)` is exactly 8 bits. 255 fits; 256 does not
// (it wraps to 0). Declare `byte` with that type.

#include <assert.h>

int main(void)
{
    unsigned _BitInt(8) byte = 255;

    static_assert(_Generic(byte, unsigned _BitInt(8): 1, default: 0));
    static_assert(sizeof(byte) == 1);
    assert(byte == 255);
    assert((unsigned _BitInt(8))(byte + 1) == 0);
    return 0;
}
