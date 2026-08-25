// I AM NOT DONE
//
// A classic C23 swap macro does not hard-code the type. `typeof(a)`
// gives you a temporary of whatever `a` is.
//
// Finish SWAP so both calls in main work.

#include <assert.h>

#define SWAP(a, b) do {               \
        /* TODO: a typed temporary */ \
    } while (0)

int main(void)
{
    int i = 1, j = 2;
    SWAP(i, j);
    assert(i == 2 && j == 1);

    double x = 1.5, y = 3.5;
    SWAP(x, y);
    assert(x == 3.5 && y == 1.5);
    return 0;
}
