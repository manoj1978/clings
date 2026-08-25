# _BitInt

`_BitInt(N)` is a signed integer with exactly N bits (including the sign
bit). `unsigned _BitInt(N)` has N value bits. `N` is a constant expression.

```c
unsigned _BitInt(8)  byte = 255;
signed   _BitInt(4)  nibble = 7;   /* range -8..7 */
```

Literals use the suffixes `wb` / `WB` (signed) and `uwb` / `UWB` (unsigned).
The width of the literal is the smallest N that can hold the value:

```c
0b1111uwb   /* unsigned _BitInt(4) */
6wb         /* _BitInt(4)  — 6 needs 3 value bits + sign */
```

Arithmetic wraps at that exact width: `unsigned _BitInt(3)` is modulo 8.

## Reading

- https://en.cppreference.com/w/c/language/arithmetic_types
