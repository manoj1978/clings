// I AM NOT DONE
//
// A `case` that falls into the next one is usually a bug. When it is
// deliberate, mark it:
//
//     case 1:
//         r += 1;
//         [[fallthrough]];
//     case 2:
//         r += 2;
//         break;
//
// Built with `-Werror=implicit-fallthrough`.

#include <assert.h>

int score(int tier)
{
    int r = 0;
    switch (tier) {
    case 1:
        r += 10;
    case 2:
        r += 5;
        break;
    default:
        break;
    }
    return r;
}

int main(void)
{
    assert(score(1) == 15); /* 10 from case 1, then 5 from case 2 */
    assert(score(2) == 5);
    return 0;
}
