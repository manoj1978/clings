// I AM NOT DONE
//
// `constexpr int n = 4;` is an integer constant expression. You can use
// it as an array length and inside `static_assert`.
//
// Replace `???` with `constexpr`.

#include <assert.h>

??? int n = 4;
int cells[n];

static_assert(n == 4);
static_assert(sizeof(cells) == 4 * sizeof(int));

int main(void)
{
    cells[0] = 1;
    assert(cells[0] == 1);
    return 0;
}
