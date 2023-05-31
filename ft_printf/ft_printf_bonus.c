/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:13:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:38:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type1(char c, int *ret)
{
	int	tmp;

	tmp = ft_putchar(c);
	if (tmp < 0)
		return (-1);
	*ret += tmp;
	return (*ret);
}

static int	print_type2(t_flag f, int *ret, va_list ap)
{
	int	tmp;

	tmp = ft_print_format(f, ap);
	if (tmp < 0)
		return (-1);
	*ret += tmp;
	return (*ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;
	t_flag	f;

	va_start(ap, str);
	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (print_type1(str[i], &ret) < 0)
				return (-1);
		}
		else
		{
			f = ft_parse_format(&str[i]);
			i += f.char_read;
			if (print_type2(f, &ret, ap) < 0)
				return (-1);
		}
		i++;
	}
	return (ret);
}
