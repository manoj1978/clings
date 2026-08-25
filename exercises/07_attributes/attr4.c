// I AM NOT DONE
//
// `[[deprecated("message")]]` marks an API you do not want callers to use.
// The compiler warns at each use, with your message.
//
// Built with `-Werror=deprecated-declarations`. Call the new function.

#include <assert.h>

[[deprecated("use next")]] int prev(void)
{
    return 1;
}

int next(void)
{
    return 2;
}

int main(void)
{
    int v = prev();
    assert(v == 2);
    return 0;
}
