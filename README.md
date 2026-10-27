_This project has been created as part of the 42 curriculum by **pabartoc** (42 Heilbronn)._

# 🖨️ ft_printf - 42 Project

## 📖 Description

**ft_printf** is a project from the 42 curriculum. The goal is to recode the well-known standard C library function `printf` from `<stdio.h>`.

The main objective of this project is to learn how to use **variadic functions** in C (`<stdarg.h>`) and to develop a deep understanding of formatted output, typecasting, and clean memory management. Since this project is built without dynamic memory allocation (`malloc`) and operates directly via the `write` system call, it is highly resource-efficient, fast, and modular – making it perfectly suited for seamless integration into your own `libft`.

## ✨ Features & Supported Conversions

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It supports the following format specifiers:

| Format | Description | Implementation Details | 
| :---: | :--- | :--- | 
| `%c` | Prints a single character (`char`). | Uses `write` directly via `ft_putchar`. | 
| `%s` | Prints a string (`char *`). | Catches `NULL` pointers and prints `(null)`. | 
| `%p` | Prints a memory address (`void *`) in hexadecimal. | Adds the `0x` prefix and handles `NULL` pointers platform-specifically (e.g., `(nil)` or `0x0`). | 
| `%d` | Prints a signed decimal number (base 10). | Handles `INT_MIN` (`-2147483648`) specifically to prevent overflows. | 
| `%i` | Prints an integer in base 10. | Identical behavior to `%d` for output. | 
| `%u` | Prints an unsigned decimal number (`unsigned int`). | Processes values up to `UINT_MAX` (`4294967295`) using recursion. | 
| `%x` | Prints a number in hexadecimal (base 16) in **lowercase**. | Uses the base `"0123456789abcdef"`. | 
| `%X` | Prints a number in hexadecimal (base 16) in **uppercase**. | Uses the base `"0123456789ABCDEF"`. | 
| `%%` | Prints a single percent sign `%`. | Escapes the formatting character. | 

**Return value:** Just like the original, `ft_printf` returns the total number of characters printed as an `int` (or `-1` if the `write` system call fails).

## 📂 Project Structure

The project is modularly divided into source code (`src`) and header files (`inc`) to ensure easy integration into larger projects (like `libft`):

```text
ft_printf/
├── .gitignore
├── Makefile
├── README.md
├── inc/
│   └── ft_printf.h          # Header file containing macros, includes & prototypes
└── src/
    ├── ft_printf.c          # Main logic, parsing the format string & va_arg handling
    └── ft_printf_add_ons.c  # Helper functions for output (putchar, putstr, putnbr, putptr, puthex)
```

## 🛠️ Instructions (Compilation & Installation)

### Prerequisites

* A C compiler (e.g., `cc`, `gcc`, or `clang`)
* `make`

### Compiling the Library

Clone the repository and run `make` in the root directory:

```bash
git clone https://github.com/pyoskel/printf.git ft_printf
cd ft_printf
make
```

This will create the static library **`libftprintf.a`** in the root directory.

### Makefile Rules

* `make` or `make all`: Compiles the `.c` files into `.o` object files and archives them into `libftprintf.a`.
* `make clean`: Deletes all generated `.o` object files in the `src/` directory.
* `make fclean`: Executes `clean` and also deletes the library `libftprintf.a`.
* `make re`: Deletes everything (`fclean`) and recompiles the project from scratch (`all`).

## 🚀 Usage

To use `ft_printf` in your own code, include the header and compile your program alongside `libftprintf.a`.

### 1. Example (`main.c` in the root directory):

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int count_ft;
    int count_orig;
    int num = 42;

    ft_printf("--- Test Start ---\n");
    
    count_ft = ft_printf("ft_printf : Hello %s! Number: %d, Hex: %X, Ptr: %p, Percent: %%\n", "World", num, num, &num);
    count_orig = printf("printf    : Hello %s! Number: %d, Hex: %X, Ptr: %p, Percent: %%\n", "World", num, num, &num);

    ft_printf("Return ft_printf: %d | Return printf: %d\n", count_ft, count_orig);
    return (0);
}
```

### 2. Compile and Run:

Since the header file is located in the `inc/` folder, we pass the `-I inc` flag to the compiler:

```bash
# 1. Build the library
make

# 2. Compile main.c with the library
cc main.c libftprintf.a -I inc -o test_printf

# 3. Run the program
./test_printf
```

## 🧪 Testing

### Edge Cases to Consider
When testing your implementation, pay special attention to:
* Passing `NULL` to `%s` and `%p`.
* Printing `INT_MIN` (`-2147483648`) and `INT_MAX`.
* Handling empty strings `""` and single character strings.
* Edge cases with `0` for hex conversions (`%x`, `%X`, `%p`).

### Using Francinette (paco)
Francinette is a popular testing framework among 42 students. To test your project:
1. Make sure Francinette is installed on your system.
2. Navigate to your `ft_printf` root directory.
3. Run the strict check:
   ```bash
   paco -s
   ```
   *(Ensure your custom `main` function is deleted or commented out before running `paco`, otherwise it will result in a compilation error!)*

### Memory Leak Testing with Valgrind
Since `ft_printf` does not use `malloc`, there shouldn't be any memory leaks. To verify this using your own `test_printf` executable:
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_printf
```
You should see `All heap blocks were freed -- no leaks are possible` in the Valgrind summary.