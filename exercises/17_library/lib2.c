// I AM NOT DONE
//
// `unreachable()` in `<stddef.h>` tells the compiler a path cannot
// happen. Use it in the `default` of a switch whose cases already cover
// every value of the enum.

#include <assert.h>
#include <stddef.h>

enum hue { Red, Green, Blue };

int channel(enum hue h)
{
    switch (h) {
    case Red:
        return 0;
    case Green:
        return 1;
    case Blue:
        return 2;
    default:
        unreach(); /* TODO: C23 spelling is unreachable(); */
    }
}

int main(void)
{
    assert(channel(Green) == 1);
    return 0;
}
