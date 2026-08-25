// I AM NOT DONE
//
// C23's null pointer constant is the keyword `nullptr`.
// It is not `NULL`, not `0`, and not `(void *)0`.
//
// Point `p` at nothing, the C23 way.

#include <stdio.h>

int main(void)
{
    int *p = null;
    if (p == nullptr) {
        puts("null");
    }
    return 0;
}
