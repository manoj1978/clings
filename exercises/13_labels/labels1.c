// I AM NOT DONE
//
// C23 allows a label to be followed by a declaration (or by `}`).
// You no longer need a dummy `;` after the label.
//
// Declare `int n = 1;` immediately after `done:`.

#include <assert.h>

int main(void)
{
    goto done;
    return 1;
done:
    /* TODO: int n = 1; */
    assert(n == 1);
    return 0;
}
