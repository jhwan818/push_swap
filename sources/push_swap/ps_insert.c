/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:52:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/02 00:55:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert(t_stack *stack_a, t_stack *stack_b, \
		t_status *status, int op)
{
	while (op > 0)
	{
		ps_action(stack_a, stack_b, RB);
		op--;
	}
	while (op < 0)
	{
		ps_action(stack_a, stack_b, RRB);
		op++;
	}
	ps_action(stack_a, stack_b, PB);
	status->max = ft_max(stack_b->front->nb, status->max);
	status->min = ft_min(stack_b->front->nb, status->min);
}

void	insert1(t_stack *stack_a, t_stack *stack_b, \
		t_status *status, int min)
{
	t_stack_n	*node;
	int			i;
	int			op;

	node = ft_stack_peek(stack_a);
	i = 0;
	while (i++ < min)
		node = node->next;
	if (node->nb > status->max || node->nb < status->min)
		op = ps_calculate_rotation1(stack_b->front, status->max);
	else
		op = ps_calculate_rotation2(node->nb, stack_b->front);
	if (op > 0)
	{
		while (min-- > 0 && op > 0)
		{
			ps_action(stack_a, stack_b, RR);
			op--;
		}
	}
	insert(stack_a, stack_b, status, op);
}

void	insert2(t_stack *stack_a, t_stack *stack_b, \
		t_status *status, int min)
{
	t_stack_n	*node;
	int			i;
	int			op;

	node = ft_stack_peek(stack_a);
	i = 0;
	while (i-- > min)
		node = node->prev;
	if (node->nb > status->max || node->nb < status->min)
		op = ps_calculate_rotation1(stack_b->front, status->max);
	else
		op = ps_calculate_rotation2(node->nb, stack_b->front);
	if (op < 0)
	{
		while (min++ < 0 && op < 0)
		{
			ps_action(stack_a, stack_b, RRR);
			op++;
		}
	}
	insert(stack_a, stack_b, status, op);
}
