// C23 allows `int first(...)` — a variadic function with no named
// parameters. Then `va_start` takes only the `va_list`:
//
//     va_start(ap);
//
// There is no last named argument to pass. Finish `first` so it returns
// the first `int` it is given.

#include <assert.h>
#include <stdarg.h>

int first(...)
{
    va_list ap;
    va_start(ap);
    int x = va_arg(ap, int);
    va_end(ap);
    return x;
}

int main(void)
{
    assert(first(42) == 42);
    assert(first(7, 8, 9) == 7);
    return 0;
}
