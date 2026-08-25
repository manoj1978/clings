// Permission bits are easier to read in binary.
//
//   READ  = 0b100
//   WRITE = 0b010
//   EXEC  = 0b001
//
// Fill in the three flags. The assertions document the combinations.

#include <assert.h>

enum {
    READ  = 0b100,
    WRITE = 0b010,
    EXEC  = 0b001,
};

int main(void)
{
    int rw = READ | WRITE;
    assert(READ == 4);
    assert(WRITE == 2);
    assert(EXEC == 1);
    assert(rw == 0b110);
    assert((READ | WRITE | EXEC) == 0b111);
    return 0;
}
