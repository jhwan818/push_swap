/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:26:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:38:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char *str)
{
	int	ret;

	if (str == NULL)
		return (-1);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

static int	putnchar(char c, int len)
{
	char	*s;
	int		ret;

	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (-1);
	ft_memset(s, (int)c, len);
	ret = write(1, s, len);
	free(s);
	return (ret);
}

static int	print_char(t_flag f, char c)
{
	int	len;
	int	count;
	int	tmp;

	len = f.f_width - 1;
	count = 0;
	tmp = 0;
	if ((!f.flag.minus) && (len > 0))
		count = putnchar(' ', len);
	if (count < 0)
		return (-1);
	if (ft_putchar(c) < 0)
		return (-1);
	count++;
	if (f.flag.minus && (len > 0))
		tmp = putnchar(' ', len);
	if (tmp < 0)
		return (tmp);
	return (count + tmp);
}

int	ft_print_format(t_flag f, va_list ap)
{
	if (f.conv.character)
		return (print_char(f, va_arg(ap, int)));
	else if (f.conv.string)
		return (print_str(ft_getstr(f, va_arg(ap, char *))));
	else if (f.conv.pointer)
		return (print_str(ft_getpointer(f, va_arg(ap, size_t))));
	else if (f.conv.decimal)
		return (print_str(ft_getdecimal(f, va_arg(ap, int))));
	else if (f.conv.integer)
		return (print_str(ft_getinteger(f, va_arg(ap, int))));
	else if (f.conv.udecimal)
		return (print_str(ft_getudecimal(f, va_arg(ap, unsigned int))));
	else if (f.conv.hexa_low)
		return (print_str(ft_gethexa_low(f, va_arg(ap, unsigned int))));
	else if (f.conv.hexa_up)
		return (print_str(ft_gethexa_up(f, va_arg(ap, unsigned int))));
	else if (f.conv.percent)
		return (print_char(f, '%'));
	else
		return (-1);
}
