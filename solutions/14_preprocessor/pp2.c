// `#embed "file"` expands to the file's bytes as a comma-separated list
// of integer constants. Drop it into an array initializer.
//
// The file `mascot.txt` (next to this source) contains the three bytes
// C, 2, 3.

#include <assert.h>

int main(void)
{
    const unsigned char mascot[] = {
#embed "mascot.txt"
    };

    static_assert(sizeof(mascot) == 3);
    assert(mascot[0] == 'C');
    assert(mascot[1] == '2');
    assert(mascot[2] == '3');
    return 0;
}
