#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
  *struct specifiers - struct specifiers
  *@specifier: conversion specifier
  *@p: func pointer
  */
typedef struct specifiers
{
	char *specifier;
	int (*p)(va_list arg_list);
} str_sp;

int print_format(const char *format, va_list args);
int print_specfier(char specifier, va_list arg_list);
int validate_specifier(char spec_char);
int print_invalid_specifier(char prev_char, char specifier, int char_count);
int printf_binary(va_list arg_list);
void printf_binary_rec(int int_arg);
void printf_int_rec(unsigned int unum);
int _write(char c);
int printf_int(va_list arg_list);
int _printf_char(va_list arg_list);
int _printf_str(va_list arg_list);
int _putchar(char c);
int _printf(const char *format, ...);
int _printf_octal(va_list arg_list);
int _printf_unsigned(va_list arg_list);
#endif
