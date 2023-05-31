/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:54:21 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 12:00:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void	*free_2d(char **ret, size_t i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (NULL);
}

static char	**fill_word(char **ret, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	wlen;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		wlen = word_len(&s[j], c);
		ret[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (ret[i] == NULL)
			return (free_2d(ret, i));
		ft_strlcpy(ret[i], &s[j], wlen + 1);
		i++;
		j += wlen;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**ret;

	if (s == NULL)
		return (NULL);
	len = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (ret == NULL)
		return (NULL);
	return (fill_word(ret, s, c, len));
}
