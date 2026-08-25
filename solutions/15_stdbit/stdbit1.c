// `<stdbit.h>` bit utilities are type-generic. On an `unsigned char`
// whose value is `0b00010000`:
//
//   stdc_count_ones      -> 1
//   stdc_leading_zeros   -> 3
//   stdc_trailing_zeros  -> 4
//
// Include the header and fill in the three calls.

#include <assert.h>
#include <stdbit.h>

int main(void)
{
    unsigned char x = 0b0001'0000;

    assert(stdc_count_ones(x) == 1);
    assert(stdc_leading_zeros(x) == 3);
    assert(stdc_trailing_zeros(x) == 4);
    return 0;
}
