/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:49:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:36:57 by junghwle         ###   ########.fr       */
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

char	*ft_getpointer(t_flag f, size_t p)
{
	char	*pointer;
	char	*ret;
	int		slen;
	int		size;

	pointer = ft_hltoa(p);
	if (pointer == NULL)
		return (NULL);
	ret = ft_strjoin("0x", pointer);
	free(pointer);
	if (ret == NULL)
		return (NULL);
	slen = ft_strlen(ret);
	size = ft_getmax(f.f_width, slen);
	return (create_str(ret, slen, size, f));
}
