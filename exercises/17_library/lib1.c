// I AM NOT DONE
//
// `strdup` is standard C23. It allocates a copy of a string; you free
// the copy. Replace the broken call with `strdup(src)`.

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *src = "c23";
    char *copy = str_dup(src);

    assert(copy != nullptr);
    assert(copy != src);
    assert(strcmp(copy, src) == 0);
    free(copy);
    return 0;
}
