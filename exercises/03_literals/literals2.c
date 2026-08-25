// I AM NOT DONE
//
// C23 digit separators are the apostrophe `'`, not underscore.
// `1'000'000` is one million. `1_000_000` is a syntax error (that suffix
// is what Python, Rust, and Java use — C does not).
//
// Fix the literal.

#include <assert.h>

int main(void)
{
    long million = 1_000_000;
    assert(million == 1000000);
    return 0;
}
