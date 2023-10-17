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
int print_char(va_list ap);
int print_string(va_list ap);
int print_mod(va_list ap);

#endif
