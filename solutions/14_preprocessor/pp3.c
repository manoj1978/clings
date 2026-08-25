// `__has_include(<header.h>)` is 1 when the implementation can include
// that header. Use it to pick the branch that includes `<stdbit.h>`.

#include <assert.h>

#if __has_include(<stdbit.h>)
#include <stdbit.h>
#define GOT_STDBIT 1
#else
#define GOT_STDBIT 0
#endif

int main(void)
{
    static_assert(GOT_STDBIT == 1);
#if GOT_STDBIT
    assert(stdc_count_ones((unsigned char)0xF) == 4);
#endif
    return 0;
}
