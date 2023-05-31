/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:24:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:38:54 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	arg_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_utoa_rec(char *ret, unsigned int n, size_t *i)
{
	if (n > 9)
		ft_utoa_rec(ret, n / 10, i);
	ret[(*i)++] = n % 10 + '0';
}

char	*ft_utoa(unsigned int u)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (arg_len(u) + 1));
	if (ret == NULL)
		return (NULL);
	ft_utoa_rec(ret, u, &i);
	ret[i] = '\0';
	return (ret);
}
