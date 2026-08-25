# Enums with a fixed type

C23 enums may name their underlying type, like C++:

```c
enum color : unsigned char { Red, Green, Blue };
enum big  : uint64_t      { Huge = 1ULL << 40 };
```

`sizeof(enum color)` is then `sizeof(unsigned char)`. The type must be
wide enough for every enumerator.

## Reading

- https://en.cppreference.com/w/c/language/enum
