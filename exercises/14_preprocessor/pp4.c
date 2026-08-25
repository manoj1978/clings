// I AM NOT DONE
//
// `__VA_OPT__(x)` expands to `x` only when `__VA_ARGS__` is not empty.
// That lets a macro accept zero extra arguments without a trailing comma:
//
//     LOG("hi\n");
//     LOG("%d\n", 3);
//
// Finish the macro. `???` is standing in for `__VA_OPT__(,)`.

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define LOG(fmt, ...) printf(fmt ??? __VA_ARGS__)

int main(void)
{
    LOG("ok\n");
    LOG("%s\n", "ok");
    assert(strcmp("ok", "ok") == 0);
    return 0;
}
