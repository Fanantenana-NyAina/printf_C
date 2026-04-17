*This project has been created as part of the 42 curriculum by fananrak.*

# ft_printf

## Description

`ft_printf` is a partial re-implementation of the C standard library `printf()` function.
The goal is to understand how formatted output works internally, and to discover
**variadic functions** in C — functions that accept a variable number of arguments.

The function parses a format string, detects `%` specifiers, and calls the appropriate
handler for each one. It returns the total number of characters written, just like
the original `printf()`.

**Supported conversions:**

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hexadecimal) |
| `%d` | Decimal integer (signed) |
| `%i` | Integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Literal percent sign |

## Instructions

### Compilation

```bash
make
```

This produces `libftprintf.a` at the root of the repository.

### Use in another project

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

Include the header in your source file:

```c
#include "ft_printf.h"
```

### Makefile rules

```bash
make          # build the library
make clean    # remove .o files
make fclean   # remove .o files and libftprintf.a
make re       # fclean + make
```

## Testing

### Step 1 — Build the library

```bash
make
```

You should see something like:
```
cc -Wall -Wextra -Werror -c ft_printf.c -o ft_printf.o
...
ar rcs libftprintf.a ft_printf.o ft_printf_utils.o ft_printf_numbers.o
```

### Step 2 — Create a test file

Create a file called `main.c` at the root of the repository with this content:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int x;

    x = 42;
    ft_printf("=== %%c ===\n");
    ft_printf("char        : %c\n", 'A');

    ft_printf("=== %%s ===\n");
    ft_printf("string      : %s\n", "hello 42");
    ft_printf("NULL string : %s\n", (char *)NULL);

    ft_printf("=== %%d and %%i ===\n");
    ft_printf("positive    : %d\n", 42);
    ft_printf("negative    : %d\n", -42);
    ft_printf("zero        : %d\n", 0);
    ft_printf("INT_MIN     : %d\n", -2147483648);

    ft_printf("=== %%u ===\n");
    ft_printf("unsigned    : %u\n", 4294967295u);

    ft_printf("=== %%x and %%X ===\n");
    ft_printf("hex lower   : %x\n", 255);
    ft_printf("hex upper   : %X\n", 255);
    ft_printf("hex zero    : %x\n", 0);

    ft_printf("=== %%p ===\n");
    ft_printf("pointer     : %p\n", (void *)&x);
    ft_printf("NULL ptr    : %p\n", (void *)NULL);

    ft_printf("=== %%%% ===\n");
    ft_printf("percent     : 100%%\n");

    return (0);
}
```

### Step 3 — Compile and run

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test && ./test
```

### Step 4 — Expected output

```
=== %c ===
char        : A
=== %s ===
string      : hello 42
NULL string : (null)
=== %d and %i ===
positive    : 42
negative    : -42
zero        : 0
INT_MIN     : -2147483648
=== %u ===
unsigned    : 4294967295
=== %x and %X ===
hex lower   : ff
hex upper   : FF
hex zero    : 0
=== %p ===
pointer     : 0x... (your address, will differ)
NULL ptr    : (nil)
=== %% ===
percent     : 100%
```

### Step 5 — Clean up before submitting

```bash
make fclean
```

This removes all `.o` files and `libftprintf.a`. Never submit with object files or the compiled library — only your source files.

---

## Algorithm and Data Structure

`ft_printf` works in two phases:

**1. Parsing the format string**

The main function loops over each character of the format string:
- Regular character → write it directly, increment count by 1
- `%` → read the next character (the specifier), call the matching handler

**2. Handlers**

Each handler is responsible for one type of output and returns the number
of characters it wrote. `ft_printf` accumulates these into a total count.

**Number conversion (iterative buffer approach)**

For `%d`, `%u`, `%x`, `%X`, `%p`, digits are extracted using successive
divisions and stored in a fixed-size stack buffer in reverse order, then
printed forward. This avoids any dynamic memory allocation.

Example with `142`:
```
142 % 10 = 2  → buf[0] = '2'
14  % 10 = 4  → buf[1] = '4'
1   % 10 = 1  → buf[2] = '1'

read backwards: '1' '4' '2' → prints 142 ✅
```

Buffer sizes are always sufficient:
- `int` : max 11 chars (`-2147483648`)
- `unsigned int` : max 10 chars
- `unsigned long` (pointer) : max 16 hex digits + `0x` prefix (18 chars)

## Resources

- `man 3 printf` — official printf documentation
- `man 3 stdarg` — va_list, va_start, va_arg, va_end
- [cppreference — fprintf](https://en.cppreference.com/w/c/io/fprintf)
- [GeeksForGeeks — Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [42 Cursus Gitbook — ft_printf guide](http://42-cursus.gitbook.io/guide/1-rank-01/ft_printf)
- [42 Norm](https://github.com/42School/norminette)

### AI usage

AI (Claude, NotebookLM) was used as a learning assistant during this project:
- To understand how variadic functions work (`va_list`, `va_arg`, etc.)
- To clarify the difference between recursive and iterative approaches for number printing
- To debug return value logic on edge cases (e.g. `INT_MIN`, `NULL` pointer, zero)
