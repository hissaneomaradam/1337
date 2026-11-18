*This project has been created as part of the 42 curriculum by ohissane.*

# ft_printf

A custom implementation of the C standard library's `printf()` function.

## Description

The goal of **ft_printf** is to recreate the behavior of the original `printf()` function from the C standard library.

This project introduces variadic functions in C and provides an opportunity to understand how functions can receive a variable number of arguments.

The implementation handles format specifiers, retrieves the corresponding arguments, converts values into printable representations, and writes the resulting output to the standard output.

### Supported conversions

| Specifier | Description |
|:---:|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal number using lowercase letters. |
| `%X` | Prints a hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

Clone the repository:

```bash
git clone https://github.com/hissaneomaradam/1337.git
cd 1337/CommonCore/ft_printf
```

Compile the library:

```bash
make
```

This generates the static library:

```text
libftprintf.a
```

Available Makefile rules:

| Command | Description |
|---|---|
| `make` | Compiles the library. |
| `make all` | Builds the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Rebuilds everything. |

### Usage

Include the header file in your C source file:

```c
#include "ft_printf.h"

int main(void)
{
    int ret;

    ret = ft_printf("Hello, %s! Number: %d\n", "1337", 42);
    return (0);
}
```

Compile your program with the library:

```bash
cc main.c -I. -L. -lftprintf -o program
```

Run it:

```bash
./program
```

The function returns the number of characters printed, or `-1` if a writing error occurs.

## Algorithm and Data Structure

### 1. Variadic arguments

The main challenge of this project is handling a variable number of arguments.

The implementation uses the `va_list` type provided by `<stdarg.h>` to access arguments passed to `ft_printf()`.

The variadic argument handling follows three main operations:

- `va_start()` initializes the argument traversal.
- `va_arg()` retrieves the next argument using the expected type.
- `va_end()` finishes the traversal.

The format string determines which type must be retrieved for each conversion.

For example:

```c
ft_printf("%s is %d years old", "Adam", 21);
```

The `%s` conversion retrieves a string, while `%d` retrieves an integer.

### 2. Format parsing

The format string is processed sequentially using a pointer.

The implementation examines each character:

- If the character is not `%`, it is written directly.
- If the character is `%`, the next character is interpreted as a conversion specifier.
- The corresponding argument is retrieved and passed to the appropriate output function.

This approach avoids unnecessary storage of the format string or its arguments.

### 3. Conversion handling

The `handle_args()` function acts as a dispatcher.

It identifies the conversion specifier and calls the appropriate helper function.

Each helper is responsible for printing a specific type of value:

- Character and string output.
- Signed and unsigned decimal numbers.
- Pointer addresses.
- Lowercase and uppercase hexadecimal numbers.
- Literal percent signs.

Separating conversions into individual functions keeps the implementation modular and easier to maintain.

### 4. Number conversion

Numbers are converted into printable characters using arithmetic operations.

For decimal numbers, the implementation extracts digits using division and modulo operations.

For hexadecimal numbers, the same principle is applied using base 16 instead of base 10.

Recursive digit printing allows the most significant digit to be printed before the remaining digits.

### 5. Data structures and design choices

The implementation relies on simple data structures rather than complex containers.

| Data structure | Purpose |
|---|---|
| `va_list` | Maintains the state used to retrieve variadic arguments. |
| `const char *` | Traverses the format string. |
| `int` | Tracks the number of characters printed and output status. |

The design prioritizes modularity, readability, and separation of responsibilities.

Each helper function handles a specific output operation, while the main function coordinates parsing and argument retrieval.

## Project Structure

```text
ft_printf/
├── ft_printf.c       # Main printf implementation
├── ft_printf.h       # Header and function prototypes
├── ft_putchar.c      # Character output
├── ft_putstr.c       # String output
├── ft_putnbr.c       # Signed integer output
├── ft_putnbr_u.c     # Unsigned integer output
├── ft_putptr.c       # Pointer address output
├── ft_putlhex.c      # Lowercase hexadecimal output
├── ft_putuhex.c      # Uppercase hexadecimal output
├── ft_write.c        # Writing utility
├── handle_args.c     # Conversion dispatcher
├── Makefile          # Library compilation rules
└── README.md
```

## Resources

### Documentation

- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h — C reference](https://en.cppreference.com/w/c/variadic.html)
- [write(2) — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- [GNU C Library — Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)

### AI Usage

AI tools were used as learning and support during this project.

They helped with:

- Understanding variadic functions and the `va_list` mechanism.
- Clarifying how format specifiers determine argument types.
- Discussing the implementation and organization of conversion functions.
- Identifying potential edge cases and suggesting test scenarios.
- Understanding return values and error handling when using `write()`.

AI was used as a learning aid to clarify concepts.

