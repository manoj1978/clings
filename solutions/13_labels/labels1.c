// C23 allows a label to be followed by a declaration (or by `}`).
// Delete the dummy `;` after `done:` so the declaration is the labeled
// statement.

#include <assert.h>

int main(void)
{
    goto done;
    return 1;
done:
    int n = 1;
    assert(n == 1);
    return 0;
}
