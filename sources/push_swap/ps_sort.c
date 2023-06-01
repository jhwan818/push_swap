/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:13:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/02 01:05:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	state2(t_stack *stack_a, t_stack *stack_b, t_status status)
{	
	while (stack_b->size > 0)
	{
		if (stack_b->front->nb > status.max || stack_b->front->nb < status.min)
		{
			while (stack_a->front->nb != status.min)
				ps_action(stack_a, stack_b, RRA);
		}
		else
		{
			while (stack_a->front->nb < stack_b->front->nb || \
					stack_a->rear->nb > stack_b->front->nb)
				ps_action(stack_a, stack_b, RA);
		}
		ps_action(stack_a, stack_b, PA);
		status.max = ft_max(stack_a->front->nb, status.max);
		status.min = ft_min(stack_a->front->nb, status.min);
	}
	while (stack_a->front->nb > stack_a->rear->nb)
		ps_action(stack_a, stack_b, RA);
}

static void	state1(t_stack *stack_a, t_stack *stack_b, t_status status)
{
	t_status	tmp1;
	t_status	tmp2;

	while (stack_a->size > 3)
	{
		status.op = INT_MAX;
		tmp1 = ps_calculate_op(stack_a->front, stack_b->front, status, 0);
		tmp2 = ps_calculate_op_rev(stack_a->rear, stack_b->front, status, 1);
		if (tmp1.op < tmp2.op)
			insert1(stack_a, stack_b, &status, tmp1.pos);
		else
			insert2(stack_a, stack_b, &status, tmp2.pos);
	}
	ps_sort_three(stack_a, stack_b);
	status.max = stack_a->front->nb;
	status.min = stack_a->front->nb;
	status.max = ft_max(stack_a->front->next->nb, status.max);
	status.max = ft_max(stack_a->rear->nb, status.max);
	status.min = ft_min(stack_a->front->next->nb, status.min);
	status.min = ft_min(stack_a->rear->nb, status.min);
	state2(stack_a, stack_b, status);
}

void	ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_status	status;

	ps_action(stack_a, stack_b, PB);
	ps_action(stack_a, stack_b, PB);
	if (stack_b->front->nb > stack_b->front->next->nb)
	{
		status.max = stack_b->front->nb;
		status.min = stack_b->front->next->nb;
	}
	else
	{
		status.max = stack_b->front->next->nb;
		status.min = stack_b->front->nb;
	}
	state1(stack_a, stack_b, status);
}
