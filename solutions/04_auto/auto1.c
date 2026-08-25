// `auto` infers the type from the initializer:
//     auto n = 42;     // int
//     auto x = 1.5;    // double
//
// Replace `???` with `auto`. The `_Generic` check requires `answer` to be
// an `int`.

#include <assert.h>

int main(void)
{
    auto answer = 6 * 7;

    static_assert(_Generic(answer, int: 1, default: 0),
                  "answer should be int");
    assert(answer == 42);
    return 0;
}
