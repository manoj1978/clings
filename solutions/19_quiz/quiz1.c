// Capstone. Fill in the C23 spellings so every assertion holds.
// You already saw each of these in an earlier exercise.

#include <assert.h>
#include <stddef.h>

constexpr int width = 4;
int cells[width];

[[nodiscard]] int answer(void)
{
    return 0b101010;
}

int main(void)
{
    auto n = 6 * 7;
    double d = 1.5;
    typeof(d) copy = d;

    bool ok = true;
    int *p = nullptr;

    int code = answer();

    static_assert(width == 4);
    static_assert(_Generic(n, int: 1, default: 0));
    static_assert(_Generic(copy, double: 1, default: 0));
    static_assert(_Generic(p, int *: 1, default: 0));

    assert(n == 42);
    assert(ok == true);
    assert(p == nullptr);
    assert(code == 42);
    assert(copy == 1.5);
    cells[0] = 1;
    assert(cells[0] == 1);
    return 0;
}
