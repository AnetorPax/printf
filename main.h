#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>


#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int _putchar(int c);
int _puts(char *str);
int _print_decimal(va_list args);
int spec_format(const char *format, va_list args);
int _print_Unsignd(va_list args);
int _format_out(char specifier, va_list args);
int _handle_custom_specifier(char specifier, va_list args);
int _print_hex_upper(va_list args);
int _print_hex(va_list args);
int _print_octal(va_list args);
int _print_unsigned_decimal(va_list args);
int _print_string_special(char *str);
int _is_non_printable(char c);
char _to_hex(int num);
int _print_binary(va_list args);
int _print_address(va_list args);
int _print_hex_address(uintptr_t addr);






#endif /* MAIN_H */
