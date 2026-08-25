// I AM NOT DONE
//
// Return a real `bool`. In C23, `true` is not an `int`.
// The `_Generic` assertion at the bottom will not accept a function that
// returns `int`.

#include <assert.h>

??? is_even(int n)
{
    // TODO: return true when n is even, false otherwise
}

int main(void)
{
    assert(is_even(2) == true);
    assert(is_even(3) == false);
    static_assert(_Generic(true, bool: 1, default: 0),
                  "true should have type bool in C23");
    return 0;
}
