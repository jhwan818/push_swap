/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:14:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 11:57:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillarg(char *s, int n)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	while (n != 0)
	{
		s[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

static char	*ft_reverse(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	ret = (char *)malloc(sizeof(char) * 12);
	if (ret == NULL)
		return (NULL);
	ret = ft_fillarg(ret, n);
	ret = ft_reverse(ret);
	return (ret);
}
