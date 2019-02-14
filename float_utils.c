#include "ft_printf.h"


char *long_double_to_str(long double num, int prec)
{
	char *str = (char*)malloc(sizeof(char) * 100);
	ft_bzero(str, 100);
	int i = 0;
	unsigned long Integral = num;
	long double fractional = num - Integral;
	while (Integral)
	{
		int rem = Integral % 10;
		str[i] = (rem +'0');
		Integral /= 10;
		i++;
	}
	str[i] = '.';
	i++;
	while (prec--)
	{
		fractional *= 10;
		Integral = fractional;
		fractional = fractional - Integral;
		str[i] = Integral + '0';
		i++;
	}
	return str;
}


void	reverse_integ(char **str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
while ((*str)[i] && (*str)[i] != '.')
		i++;
	if (i == 0 || i == 1)
		return ;
	j = 0;
	i--;
	while (i > j)
	{
		tmp = (*str)[j];
		(*str)[j] = (*str)[i];
		(*str)[i] = tmp;
		j++;
		i--;
	}
}

void	move_str_right(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(*str);
	
	i = 1;
	j = 0;
	(*str)[0] = ' ';
	while ((*str)[i])
	{
		(*str)[i] = tmp[j];
		i++;
		j++;
	}
	free(tmp);
}

void	round_nine(char **str, int i)
{
	if ((*str)[i + 1] >= '5')
	{
		if ((*str)[i] == '9')
		{
			(*str)[i] = '0';
			i--;
			while ((*str)[i] && (*str)[i] == '9')
			{
				(*str)[i] = '0';
				i--;
				if ((*str)[i] == '.')
				{
					i--;
					if ((*str)[i] != '9')
						break ;
					move_str_right(str);
				}
			}
			(*str)[i] += 1;
		}
		else if ((*str)[i] != '.')
			(*str)[i] += 1;
	}
}

void	print_rounded(char **str, int prec)
{
	int		i;

	i = 0;
	while ((*str)[i] != '.')
		i++;
	while (prec--)
		i++;
	round_nine(str, i);

	/*printf("\nstr: %s|i: %d\n", *str, i);*/
}

void	convert_fpart(char **str, int i, double fpart, int prec)
{
	unsigned long ipart;

	(*str)[i] = '.';
	reverse_integ(str);
	i++;
	while (prec--)
	{
		fpart *= 10;
		ipart = fpart;
		fpart = fpart - ipart;
		(*str)[i] = ipart + '0';
		i++;
	}
}

char *double_to_str(double num, int prec)
{
	char			*str;
	int				i;
	unsigned long	ipart;
	double			fpart;

	str = (char*)malloc(sizeof(char) * 100 + prec);
	i = 0;
	if (num < 0)
		num *= -1;
	ipart = num;
	fpart = num - ipart;
	if (ipart == 0)
		str[i++] = '0';
	while (ipart)
	{
		int rem = ipart % 10;
		str[i] = (rem +'0');
		/*write(1, &str[i], 1);*/
		ipart /= 10;
		i++;
	}
	convert_fpart(&str, i, fpart, prec);
	return str;
}


