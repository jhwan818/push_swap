/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getudecimal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:37:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:37:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string2(t_flag f, char *str, int width)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (width + 1));
	if (ret != NULL)
	{
		ft_memset(ret, ' ', width);
		if (f.flag.minus)
			ft_memcpy(ret, str, ft_strlen(str));
		else
			ft_memcpy(&ret[width - ft_strlen(str)], str, ft_strlen(str));
		ret[width] = '\0';
	}
	free(str);
	return (ret);
}

static char	*create_string(t_flag f, char *str, int width)
{
	if (f.flag.zero && !f.flag.minus)
		return (fill_zero(str, width));
	return (create_string2(f, str, width));
}

char	*ft_getudecimal(t_flag f, unsigned int u)
{
	char	*str;
	int		width;
	int		slen;

	if (f.flag.precition && f.p_width == 0 && u == 0)
		str = ft_strdup("");
	else
		str = ft_utoa(u);
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	width = ft_getmax(f.f_width, slen);
	if (!f.flag.precition)
		return (create_string(f, str, width));
	else
	{
		if ((int)f.p_width >= width)
			width = f.p_width;
		str = fill_zero(str, ft_getmax(slen, f.p_width));
		if (str == NULL)
			return (NULL);
		return (create_string2(f, str, width));
	}
}
