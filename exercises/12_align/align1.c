// I AM NOT DONE
//
// `alignas(N)` requests alignment. `alignof(x)` reports it.
// Both are keywords in C23 — no header required.
//
// Align `buf` to 32 bytes.

#include <assert.h>
#include <stdint.h>

int main(void)
{
    unsigned char buf[64]; /* TODO: alignas(32) */

    static_assert(alignof(buf) == 32);
    assert(((uintptr_t)buf % 32) == 0);
    return 0;
}
