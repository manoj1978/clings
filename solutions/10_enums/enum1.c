// Pin the enum to `uint8_t` so it is exactly one byte.
// Syntax: `enum name : type { ... }`

#include <assert.h>
#include <stdint.h>

enum color : uint8_t { Red, Green, Blue };

static_assert(sizeof(enum color) == 1);
static_assert(_Generic(Red, enum color: 1, default: 0));

int main(void)
{
    enum color c = Blue;
    assert(c == 2);
    return 0;
}
