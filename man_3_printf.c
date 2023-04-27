.TH _PRINTF "1" "28 APRIL 2023" "0x11. C - printf"
.SH NAME
_printf - print data according to a format
.SH SYNOPSIS
.B printf FORMAT [ARGUMENT]...
.SH DESCRIPTION
Prints ARGUMENT(s) based on FORMAT

Format specifiers (beginning with %), the additional arguments following format are formatted and inserted.

_printf will also take an indefinite amount of arguments.

Example:
_printf("%s", text);

In the Example print the value of text with %s give the format of text.

.B The conversion specifiers

.IP %c
- prints character.
.IP %s
- prints string.
.IP %%
- prints percentage symbol.
.IP %d
- prints decimal.
.IP %i
- prints integer number.

.SH SEE ALSO
.I printf (3)
.SH AUTHOR
Obasi Emmanuel ( Eobago )
Lemaeke Ejimoforh ( Lemaekeejimofor101 )
