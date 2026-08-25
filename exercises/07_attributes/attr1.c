// I AM NOT DONE
//
// `[[nodiscard]]` means "the return value is the point". Ignoring it is
// a warning; this exercise compiles with `-Werror=unused-result`.
//
// Store the result of `must_check` and use it. A `(void)` cast would
// silence the warning, but the assertion would then fail.

#include <assert.h>

[[nodiscard]] int must_check(void)
{
    return 42;
}

int main(void)
{
    int code = 0;
    must_check();
    assert(code == 42);
    return 0;
}
