/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdecimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:22:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:36:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string2(t_flag f, char *str, char sign, int width)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (width + 1));
	if (ret != NULL)
	{
		ft_memset(ret, ' ', width);
		if (sign)
			str = ft_strappend(sign, str);
		if (str == NULL)
		{
			free(ret);
			return (NULL);
		}
		if (f.flag.minus)
			ft_memcpy(ret, str, ft_strlen(str));
		else
			ft_memcpy(&ret[width - ft_strlen(str)], str, ft_strlen(str));
		ret[width] = '\0';
	}
	free(str);
	return (ret);
}

static char	*create_string(t_flag f, char *str, char sign, int width)
{
	char	*ret;

	if (f.flag.zero && !f.flag.minus)
	{
		ret = fill_zero(str, width);
		if (ret != NULL && sign)
			ret[0] = sign;
		return (ret);
	}
	return (create_string2(f, str, sign, width));
}

static char	*precition_control(t_flag f, char *str, char sign, int width)
{
	if ((int)f.p_width >= width)
	{
		width = f.p_width;
		if (sign)
			width++;
	}
	str = fill_zero(str, ft_getmax(ft_strlen(str), f.p_width));
	if (str == NULL)
		return (NULL);
	return (create_string2(f, str, sign, width));
}

char	*ft_getdecimal(t_flag f, int d)
{
	char	*str;
	char	sign;
	int		width;
	int		slen;

	if (f.flag.precition && f.p_width == 0 && d == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(d);
	str = set_sign(str, &sign, f);
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (sign)
		slen++;
	if (f.flag.space && d >= 0)
		f.f_width--;
	width = ft_getmax(f.f_width, slen);
	if (!f.flag.precition)
		str = create_string(f, str, sign, width);
	else
		str = precition_control(f, str, sign, width);
	if (f.flag.space && d >= 0 && str != NULL)
		str = ft_strappend(' ', str);
	return (str);
}
