// Binary integer literals use a `0b` or `0B` prefix.
// `0b101010` is 42.
//
// Replace the placeholder with a binary literal equal to 42.

#include <assert.h>

int main(void)
{
    int answer = 0b101010;
    assert(answer == 42);
    return 0;
}
