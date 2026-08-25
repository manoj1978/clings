// I AM NOT DONE
//
// `_Generic` sees the *type* of the selector. `nullptr` is `nullptr_t`.
// `NULL` is typically `void *` (or `int` on some old libraries).
//
// Make `is_nullptr` report 1 for `nullptr`.

#include <stddef.h>
#include <assert.h>

#define is_nullptr(x) _Generic((x), \
        /* TODO: match nullptr_t */ \
        default: 0)

int main(void)
{
    assert(is_nullptr(nullptr) == 1);
    assert(is_nullptr(NULL) == 0);
    assert(is_nullptr(0) == 0);
    return 0;
}
