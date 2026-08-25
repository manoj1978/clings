// I AM NOT DONE
//
// Inference needs a value to look at. `auto n;` is a compile error.
// Give `n` an initializer.

#include <assert.h>

int main(void)
{
    auto n;
    n = 42;
    assert(n == 42);
    return 0;
}
