// I AM NOT DONE
//
// The underlying type has to be wide enough for every enumerator.
// `uint8_t` cannot hold `1UL << 32`. Pick a type that can (`uint64_t`,
// `unsigned long`, …).

#include <assert.h>
#include <stdint.h>

enum range : uint8_t { Big = 1UL << 32 };

int main(void)
{
    assert(Big == (1UL << 32));
    return 0;
}
