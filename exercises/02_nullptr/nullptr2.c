// I AM NOT DONE
//
// `nullptr` has its own type, `nullptr_t`, declared in `<stddef.h>`.
// You can store `nullptr` in a `nullptr_t` object and then assign that
// object to any pointer type.

#include <stddef.h>
#include <assert.h>

int main(void)
{
    ??? np = nullptr;
    int *p = np;
    double *q = np;

    assert(p == nullptr);
    assert(q == nullptr);
    static_assert(_Generic(np, nullptr_t: 1, default: 0));
    return 0;
}
