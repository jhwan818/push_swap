/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_len4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:56:44 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/13 18:21:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_min_pos(t_stack_n *node, size_t len)
{
	size_t	i;
	int		min;
	int		pos;

	i = 0;
	min = node->nb;
	pos = 0;
	while (i < len)
	{
		if (node->nb < min)
		{
			min = node->nb;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

void	ps_sort_len4(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	int	min_pos;

	min_pos = ps_find_min_pos(ft_stack_peek(stack_a), stack_a->size);
	if (min_pos < 2)
	{
		while (min_pos-- != 0)
			ps_action(stack_a, stack_b, RA, buff);
	}
	else
	{
		while (min_pos++ != 4)
			ps_action(stack_a, stack_b, RRA, buff);
	}
	ps_action(stack_a, stack_b, PB, buff);
	ps_sort_len3(stack_a, stack_b, buff);
	ps_action(stack_a, stack_b, PA, buff);
}
