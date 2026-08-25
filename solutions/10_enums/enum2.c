// Without a fixed underlying type, enumerators have to fit in `int`.
// `1UL << 32` does not fit in a 32-bit `int`.
//
// Give the enum a wide enough type (`unsigned long`, `uint64_t`, …).

#include <assert.h>
#include <stdint.h>

enum range : uint64_t { Big = 1UL << 32 };

int main(void)
{
    assert(Big == (1UL << 32));
    return 0;
}
