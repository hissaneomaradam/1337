_This project has been created as part of the 42 curriculum by ohissane._

# libft

## Description

**libft** is the first project of the 42 Common Core. The goal is to build, from scratch, a personal C library that re-implements a set of standard C library functions and adds extra utility functions that will be reused in later projects of the curriculum.

The project teaches the fundamentals of C programming: pointers, memory management (`malloc` / `free`), string and memory manipulation, linked lists, and writing a `Makefile` that produces a static library (`libft.a`) with `ar`. All code follows the 42 Norm and compiles with `-Wall -Wextra -Werror`.

The library is split into three parts:

1. **Part 1: libc functions.** Re-implementations of standard functions, with the same prototypes and behavior as the originals (names prefixed with `ft_`).
2. **Part 2: additional functions.** Utility functions that are not in libc or exist in a different form.
3. **Part 3: linked lists.** Functions to manipulate singly linked lists through the `t_list` structure.

## Library overview

### Part 1: libc functions

| Category                  | Functions                                                                    |
| ------------------------- | ---------------------------------------------------------------------------- |
| Character checks          | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`         |
| Character conversion      | `ft_toupper`, `ft_tolower`                                                   |
| String length and copy    | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`                                      |
| String search and compare | `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`                        |
| Memory manipulation       | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Conversion                | `ft_atoi`                                                                    |
| Allocation                | `ft_calloc`, `ft_strdup`                                                     |

### Part 2: additional functions

| Function        | Purpose                                                                                     |
| --------------- | ------------------------------------------------------------------------------------------- |
| `ft_substr`     | Returns a new string extracted from a string, from a start index and with a maximum length. |
| `ft_strjoin`    | Returns a new string that is the concatenation of two strings.                              |
| `ft_strtrim`    | Returns a copy of a string with the characters of a given set removed from both ends.       |
| `ft_split`      | Splits a string into a `NULL`-terminated array of strings using a delimiter character.      |
| `ft_itoa`       | Converts an integer to a newly allocated string, handling negative numbers.                 |
| `ft_strmapi`    | Applies a function to each character (with its index) and returns the resulting new string. |
| `ft_striteri`   | Applies a function to each character (with its index) of a string, in place.                |
| `ft_putchar_fd` | Writes a character to a file descriptor.                                                    |
| `ft_putstr_fd`  | Writes a string to a file descriptor.                                                       |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor.                                 |
| `ft_putnbr_fd`  | Writes an integer to a file descriptor.                                                     |

### Part 3: linked lists

The list functions work on this structure, defined in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

| Function          | Purpose                                                                                                                        |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| `ft_lstnew`       | Allocates and returns a new node holding the given content, with `next` set to `NULL`.                                         |
| `ft_lstadd_front` | Adds a node at the beginning of the list.                                                                                      |
| `ft_lstsize`      | Counts the nodes in the list.                                                                                                  |
| `ft_lstlast`      | Returns the last node of the list.                                                                                             |
| `ft_lstadd_back`  | Adds a node at the end of the list.                                                                                            |
| `ft_lstdelone`    | Frees one node's content using the given `del` function, then frees the node.                                                  |
| `ft_lstclear`     | Deletes and frees a node and all its successors, then sets the list pointer to `NULL`.                                         |
| `ft_lstiter`      | Applies a function to the content of every node.                                                                               |
| `ft_lstmap`       | Builds a new list by applying a function to each node's content. If an allocation fails, everything allocated so far is freed. |

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar`

### Compilation

From the root of the repository:

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # rebuilds everything from scratch
```

All files are compiled with `-Wall -Wextra -Werror`. Running `make` twice does not relink when nothing has changed.

### Usage

Include the header in your source file and link against the library:

```c
#include "libft.h"

int	main(void)
{
	ft_putstr_fd("Hello, 42!\n", 1);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
./program
```

### Checking the code

```bash
norminette        # checks every .c and .h file against the 42 Norm
```

Memory errors and leaks can be checked with:

```bash
cc -g -fsanitize=address main.c libft.a -o program && ./program
valgrind --leak-check=full ./program
```

## Resources

### References

- Linux manual pages for the libc functions (`man 3 <function>`): <https://man7.org/linux/man-pages/>
- C reference: <https://en.cppreference.com/w/c>
- GNU Make manual: <https://www.gnu.org/software/make/manual/>
- Makefile Tutorial: <https://makefiletutorial.com/>
- Valgrind documentation: <https://valgrind.org/docs/manual/>
- The 42 Norm and `norminette`
- _The C Programming Language_, Brian W. Kernighan and Dennis M. Ritchie

### Peer learning

- Discussing approaches, comparing edge cases and reviewing code with other 42 students, and peer evaluations.

### Use of AI

AI was used as a learning and checking tool, for the following tasks:

- **Learning and explanations:** understanding how the Makefile rules work, how linked lists and pointers to pointers behave, and how memory must be freed, and more.
- **Testing:** writing small test programs and using AddressSanitizer, valgrind and the tester to check edge cases and leaks.
- **Debugging and review:** reviewing my attempts and pointing out errors.
