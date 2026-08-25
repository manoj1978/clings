// C23 promotes `bool`, `true`, and `false` to keywords.
// You do not need `<stdbool.h>`, and you should not write `_Bool` or `1`/`0`
// when you mean a boolean.
//
// Give `ready` the C23 boolean type and set it to true.

#include <stdio.h>

int main(void)
{
    bool ready = true;

    if (ready) {
        puts("ready");
    }
    return 0;
}
