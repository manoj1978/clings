// I AM NOT DONE
//
// `[[maybe_unused]]` silences unused-variable / unused-parameter warnings
// when you *mean* to leave something unused (a placeholder, a parameter
// required by an API, a value kept for a debugger).
//
// This file is built with `-Werror=unused-variable -Werror=unused-parameter`.

int greet([[maybe_unused]] int unused_slot, int n);

int greet(int unused_slot, int n)
{
    int scratch = 0;
    return n;
}

int main(void)
{
    return greet(0, 0);
}
