/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_flush_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:01:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/13 18:19:17 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ss(const char *s1, const char *s2)
{
	if (ft_str_isequal(s1, "sa") && ft_str_isequal(s2, "sb"))
		return (1);
	else if (ft_str_isequal(s1, "sb") && ft_str_isequal(s2, "sa"))
		return (1);
	return (0);
}

static int	is_rr(const char *s1, const char *s2)
{
	if (ft_str_isequal(s1, "ra") && ft_str_isequal(s2, "rb"))
		return (1);
	else if (ft_str_isequal(s1, "rb") && ft_str_isequal(s2, "ra"))
		return (1);
	return (0);
}

static int	is_rrr(const char *s1, const char *s2)
{
	if (ft_str_isequal(s1, "rra") && ft_str_isequal(s2, "rrb"))
		return (1);
	else if (ft_str_isequal(s1, "rrb") && ft_str_isequal(s2, "rra"))
		return (1);
	return (0);
}


static void	print_buff(char **buff_elem)
{
	int	i;

	i = 0;
	while (buff_elem[i] != NULL)
	{
		if (is_ss(buff_elem[i], buff_elem[i + 1]))
		{
			ft_printf("ss\n");
			i++;
		}
		else if (is_rr(buff_elem[i], buff_elem[i + 1]))
		{
			ft_printf("rr\n");
			i++;
		}
		else if (is_rrr(buff_elem[i], buff_elem[i + 1]))
		{
			ft_printf("rrr\n");
			i++;
		}
		else
			ft_printf("%s\n", buff_elem[i]);
		i++;
	}
}

int	ps_flush_buff(const char *buffer)
{
	char	**buff_elem;
	size_t	i;

	buff_elem = ft_split(buffer, '\n');
	if (buff_elem == NULL)
		return (-1);
	print_buff(buff_elem);
	i = 0;
	while (buff_elem[i] != NULL)
		free(buff_elem[i++]);
	free(buff_elem);
	return (0);
}
