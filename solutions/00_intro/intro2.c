// clings compiles every file with `-std=c23`.
// C23 bumps the predefined macro `__STDC_VERSION__` to 202311L
// (C17 was 201710L, C11 was 201112L).
//
// Fill in the version so the static assertion holds.

#define VERSION 202311L
static_assert(__STDC_VERSION__ >= VERSION);

int main(void)
{
    return 0;
}
