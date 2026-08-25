// C23 lets you omit a parameter name you do not use. The type still has
// to be there, so callers pass the right thing; you just do not bind a
// name.
//
// `unused_name` is unused and this file is expected to fail until you
// drop the name. (If you mark it `[[maybe_unused]]` that also compiles,
// but the point of this exercise is the unnamed-parameter spelling.)

#include <assert.h>

int add_one(int, int n)
{
    return n + 1;
}

int main(void)
{
    assert(add_one(0, 41) == 42);
    return 0;
}
