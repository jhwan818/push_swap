/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:21:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:37:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(char *str, int slen, int size, t_flag f)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret != NULL)
	{
		ret = ft_memset(ret, ' ', size);
		i = size - slen;
		if (f.flag.minus)
			i = 0;
		ft_memcpy(&ret[i], str, slen);
		ret[size] = '\0';
	}
	free(str);
	return (ret);
}

char	*ft_getstr(t_flag f, char *s)
{
	char	*str;
	int		slen;
	int		size;

	if (s == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (f.flag.precition)
		slen = ft_getmin(f.p_width, slen);
	size = ft_getmax(f.f_width, slen);
	return (create_str(str, slen, size, f));
}
