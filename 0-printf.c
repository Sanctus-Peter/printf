#include"main.h"

int _printf(const char *s, ...)
{
	int i = 0, j = 0,
		flg[5] = {0, 0, 0, 0, 0};
	char *str, buff[50], c;

	/* list of arguments */
	va_list args;

	/* Initaialise list */
	va_start(args, s);

	for (; s[i] && s; i++)
	{
		flg[0] = flg[1] = flg[2] = flg[3] = flg[4] = 0;
		if (s[i] == '%')
		{
			i++;
			i += setFlags(s, flg, i, &args);
			if (s[i] == 'l')
				i++;
			switch (s[i])
			{
			case 'i':
			case 'd':
				signedNumberToString((int)va_arg(args, int),10, buff, s, i);
				j += print_string(buff, flg, 1);
				break;
			case 'p':
				signedNumberToString(va_arg(args, int),16, buff, s, i);
				j += print_string(buff, flg, 1);
				break;
			case 'x': /* hexadecimal int */
				signedNumberToString((int)va_arg(args, int),16, buff, s, i);
				j += print_string(buff, flg, 1);
				break;
			case 'o': /* octal int */
				signedNumberToString((int)va_arg(args, int), 8, buff, s, i);
				j += print_string(buff, flg, 1);
				break;
			case 'b': /* binary int */
				signedNumberToString((int)va_arg(args, int), 2, buff, s, i);
				j += print_string(buff, flg, 1);
				break;
			case 'c':
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				j++;
				break;
			case 's': /* string */
				str = va_arg(args, char *);
				j += print_string(str, flg, 1);
				break;
			case 'n': /* copy j to next arg */
				*((int *)va_arg(args, int *)) = ++j;
				break;
			default:
				write(1, &s[i], 1);
				j++;
			}
		}
		else
		{
			write(1, &s[i], 1);
			j++;
		}
	}

	/* free args list */
	va_end(args);

	/* print the result */
	return (j);
}

