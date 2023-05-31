/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:38:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:37:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_atoi(const char *str, t_flag *f)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
		f->char_read++;
	}
	return (num);
}

static void	ft_parse_flag(const char *str, t_flag *f)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (ft_strchr("-0# +", str[i]) != NULL))
	{
		if (str[i] == '-')
			f->flag.minus = TRUE;
		else if (str[i] == '0')
			f->flag.zero = TRUE;
		else if (str[i] == '#')
			f->flag.hashtag = TRUE;
		else if (str[i] == ' ')
			f->flag.space = TRUE;
		else
			f->flag.plus = TRUE;
		f->char_read++;
		i++;
	}
	f->f_width = ft_flag_atoi(&str[i], f);
}

static void	ft_parse_presition(const char *str, t_flag *f)
{
	if (*str == '.')
	{
		f->flag.precition = TRUE;
		f->char_read++;
		f->p_width = ft_flag_atoi(str + 1, f);
	}
}

static void	ft_parse_conversion(const char c, t_flag *f)
{
	if (c == 'c')
		f->conv.character = 1;
	else if (c == 's')
		f->conv.string = 1;
	else if (c == 'p')
		f->conv.pointer = 1;
	else if (c == 'd')
		f->conv.decimal = 1;
	else if (c == 'i')
		f->conv.integer = 1;
	else if (c == 'u')
		f->conv.udecimal = 1;
	else if (c == 'x')
		f->conv.hexa_low = 1;
	else if (c == 'X')
		f->conv.hexa_up = 1;
	else if (c == '%')
		f->conv.percent = 1;
	else
		f->conv.err = 1;
}

t_flag	ft_parse_format(const char *str)
{
	t_flag	f;

	ft_bzero(&f, sizeof(t_flag));
	f.char_read++;
	ft_parse_flag(str + 1, &f);
	ft_parse_presition(str + f.char_read, &f);
	ft_parse_conversion(str[f.char_read], &f);
	return (f);
}
