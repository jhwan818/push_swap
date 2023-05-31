/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:35:16 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:36:17 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_zero(char	*str, int width)
{
	char	*ret;
	int		slen;

	ret = (char *)malloc(sizeof(char) * (width + 1));
	if (ret == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memset(ret, '0', width);
	slen = ft_strlen(str);
	ft_strlcpy(&ret[width - slen], str, slen + 1);
	free(str);
	return (ret);
}
