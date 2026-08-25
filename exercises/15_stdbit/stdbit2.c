// I AM NOT DONE
//
// More of `<stdbit.h>`:
//
//   stdc_has_single_bit(x)  — power of two?
//   stdc_bit_floor(x)       — largest power of two <= x
//   stdc_bit_ceil(x)        — smallest power of two >= x
//   stdc_bit_width(x)       — floor(log2(x))+1  (0 if x is 0)
//
// Fill in the expected values for `x = 0b00001010` (10).

#include <assert.h>
#include <stdbit.h>

int main(void)
{
    unsigned char x = 0b0000'1010; /* 10 */

    assert(stdc_has_single_bit(x) == ???);
    assert(stdc_bit_floor(x) == ???);
    assert(stdc_bit_ceil(x) == ???);
    assert(stdc_bit_width(x) == ???);

    unsigned char p2 = 0b0001'0000; /* 16, already a power of two */
    assert(stdc_has_single_bit(p2) == true);
    assert(stdc_bit_floor(p2) == 16);
    assert(stdc_bit_ceil(p2) == 16);
    return 0;
}
