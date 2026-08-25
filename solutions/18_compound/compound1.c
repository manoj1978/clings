// `(int[]){1,2,3}` has automatic storage. Returning its address dangles.
// C23 lets you write `(static int[]){1,2,3}` so the array lives for the
// whole program.
//
// Add `static` to the compound literal.

#include <assert.h>

int *ones(void)
{
    return (static int[]){1, 1, 1};
}

int main(void)
{
    int *p = ones();
    assert(p[0] == 1 && p[1] == 1 && p[2] == 1);
    return 0;
}
