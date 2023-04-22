# _printf

_printf is a custom implementation of the C library function printf. It produces output according to a format string and supports several conversion specifiers and flag characters.

Features
_printf supports the following conversion specifiers:

	c: character
	s: string
	%: literal percent sign
	d, i: signed decimal integer
	u: unsigned decimal integer
	o: unsigned octal integer
	x, X: unsigned hexadecimal integer (lowercase/uppercase)
	p: pointer address
	b: unsigned binary integer
	S: string with non-printable characters replaced by their hexadecimal representation
	r: reversed string
	R: rot13-encoded string

_printf also supports the following flag characters:

	-: left-justify within field width
	+: force sign to be printed
	space: print space before positive numbers
	#: alternate form for certain conversion specifiers
	0: pad with zeros instead of spaces
