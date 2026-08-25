# Attributes

C23 standardizes `[[attribute]]` syntax. The portable ones:

| Attribute | Meaning |
| --- | --- |
| `[[nodiscard]]` | ignoring the return value is a warning |
| `[[maybe_unused]]` | do not warn about an unused name |
| `[[fallthrough]]` | this `case` is meant to fall into the next |
| `[[deprecated]]` | using this name is a warning |
| `[[noreturn]]` | the function does not return |

```c
[[nodiscard]] int open_db(void);
[[deprecated("use open_db")]] int open_database(void);
```

clings turns the relevant warnings into errors for these exercises, so you
have to address them.

## Reading

- https://en.cppreference.com/w/c/language/attributes
