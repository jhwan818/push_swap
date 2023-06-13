/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_len5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:24:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/13 18:46:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_find_2min_pos(t_stack_n *node, size_t len, int *min, int *min2)
{
	size_t	i;

	i = 0;
	*min = INT_MAX;
	*min2 = INT_MAX;
	while (i < len)
	{
		if (node->nb < *min)
		{
			*min2 = *min;
			*min = node->nb;
		}
		else if (node->nb < *min2 && node->nb != *min)
			*min2 = node->nb;
		node = node->next;
		i++;
	}
}

void	ps_sort_len5(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	int			min;
	int			min2;
	t_stack_n	*node;
	int			i;

	node = ft_stack_peek(stack_a);
	ps_find_2min_pos(node, stack_a->size, &min, &min2);
	i = 0;
	while (i < 5)
	{
		node = ft_stack_peek(stack_a);
		if (node->nb == min || node->nb == min2)
			ps_action(stack_a, stack_b, PB, buff);
		else
			ps_action(stack_a, stack_b, RA, buff);
		i++;
	}
	ps_sort_len3(stack_a, stack_b, buff);
	ps_sort_len2_b(stack_a, stack_b, buff);
}
