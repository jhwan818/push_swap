/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:40:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/23 20:40:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_base
{
	char	*base;
	size_t	len;
}	t_base;

static size_t	arg_len(size_t n)
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

static void	ft_htoa_rec(char *ret, size_t h, size_t *i, t_base b)
{
	if (h >= b.len)
		ft_htoa_rec(ret, h / b.len, i, b);
	ret[(*i)++] = b.base[h % b.len];
}

char	*ft_htoa_base(size_t h, char *base)
{
	char	*ret;
	size_t	i;
	t_base	b;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (arg_len(h) + 1));
	if (ret == NULL)
		return (NULL);
	b.base = base;
	b.len = ft_strlen(base);
	ft_htoa_rec(ret, h, &i, b);
	ret[i] = '\0';
	return (ret);
}
