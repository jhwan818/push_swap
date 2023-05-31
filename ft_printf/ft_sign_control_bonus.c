/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_control_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:21 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:38:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_sign(char *str, char *sign, t_flag f)
{
	char	*tmp;

	if (str == NULL)
		return (NULL);
	if (str[0] == '-')
	{
		*sign = '-';
		tmp = ft_strdup(&str[1]);
		free(str);
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	else if (f.flag.plus)
		*sign = '+';
	else
		*sign = 0;
	return (str);
}

char	*ft_strappend(char c, char *s2)
{
	char	*ret;
	int		slen;

	slen = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (slen + 2));
	if (ret == NULL)
	{
		free(s2);
		return (NULL);
	}
	ret[0] = c;
	ft_strlcpy(&ret[1], s2, slen + 1);
	free(s2);
	return (ret);
}
