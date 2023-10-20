#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _write(char c);
/**
 * struct specifier - struct specifier
 * @c: conversion specifier
 * @f: the function associated
 */
typedef struct specifier
{
	char c;
	int (*f)(va_list ap);
} spec;
int _printf(const char *format, ...);
int print_c(va_list ap);
int print_str(va_list ap);
int print_mod(va_list ap);
int print_int(va_list ap);
int print_bin(va_list ap);
int print_unsigned(va_list ap);
int print_octal(va_list ap);
int print_hexa(va_list ap);
int print_HEXA(va_list ap);
int print_STR(va_list ap);
int print_rev(va_list ap);

#endif
