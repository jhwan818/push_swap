/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:06:06 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/12 23:08:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isequal(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
