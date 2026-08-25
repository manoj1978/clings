// `#elifdef NAME` is `#elif defined(NAME)`.
// `#elifndef NAME` is `#elif !defined(NAME)`.
//
// Use `#elifdef HAVE_C23` so `mode` becomes 23.

#include <assert.h>

#define HAVE_C23 1

#if defined(HAVE_C17)
#define mode 17
#elifdef HAVE_C23
#define mode 23
#else
#define mode 0
#endif

int main(void)
{
    assert(mode == 23);
    return 0;
}
