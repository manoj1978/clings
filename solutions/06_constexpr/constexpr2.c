// This is the C-vs-C++ trap. In C, `const int n = 4;` is not an integer
// constant expression: `static_assert(n == 4)` is illegal, and `int a[n]`
// at block scope is a VLA.
//
// `constexpr` is the keyword that actually produces a compile-time
// constant. Change `const` to `constexpr`.

constexpr int n = 4;
int a[n];

static_assert(n == 4);
static_assert(sizeof(a) == 4 * sizeof(int));

int main(void)
{
    return 0;
}
