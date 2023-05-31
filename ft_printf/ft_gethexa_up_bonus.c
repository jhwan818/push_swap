/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethexa_up_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:54:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:40:39 by junghwle         ###   ########.fr       */
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
		if (f.flag.hashtag)
		{
			str = ft_strappend('X', str);
			if (str != NULL)
				str = ft_strappend('0', str);
		}
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

static char	*create_string(t_flag f, char *str, int width)
{
	char	*ret;

	if (f.flag.zero && !f.flag.minus)
	{
		ret = fill_zero(str, width);
		if (ret != NULL && f.flag.hashtag)
		{
			ret[0] = '0';
			ret[1] = 'X';
		}
		return (ret);
	}
	return (create_string2(f, str, width));
}

static char	*precition_control(t_flag f, char *str, int width)
{
	if (f.flag.hashtag && (((int)f.p_width + 2) >= width))
		width = f.p_width + 2;
	else if ((int)f.p_width >= width)
		width = f.p_width;
	str = fill_zero(str, ft_getmax(ft_strlen(str), f.p_width));
	if (str == NULL)
		return (NULL);
	return (create_string2(f, str, width));
}

char	*ft_gethexa_up(t_flag f, unsigned int hu)
{
	char	*str;
	int		width;
	int		slen;

	if (f.flag.precition && f.p_width == 0 && hu == 0)
		str = ft_strdup("");
	else
		str = ft_hutoa(hu);
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (hu == 0)
		f.flag.hashtag = 0;
	if (f.flag.hashtag)
		slen += 2;
	width = ft_getmax(f.f_width, slen);
	if (!f.flag.precition)
		str = create_string(f, str, width);
	else
		str = precition_control(f, str, width);
	return (str);
}
