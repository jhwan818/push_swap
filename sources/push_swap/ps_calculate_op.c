/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:09:35 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/01 23:24:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	ps_calculate_op(t_stack_n *node_a, t_stack_n *node_b, \
		t_status status, int deep)
{
	int	op;
	int pos;

	if (deep >= status.op)
		return (status);
	pos = deep;
	if (node_a->nb > status.max || node_a->nb < status.min)
		op = ps_calculate_rotation1(node_b, status.max);
	else
		op = ps_calculate_rotation2(node_a->nb, node_b);
	if (op > 0)
		while (deep-- > 0 && op > 0)
			op--;
	op = ft_abs(op) + deep + 1;
	if (op < status.op)
	{
		status.op = op;
		status.pos = pos;
	}
	return (ps_calculate_op(node_a->next, node_b, status, deep + 1));
}

t_status	ps_calculate_op_rev(t_stack_n *node_a, t_stack_n *node_b, \
		t_status status, int deep)
{
	int	op;
	int pos;

	if (deep >= status.op)
		return (status);
	pos = deep * -1;
	if (node_a->nb > status.max || node_a->nb < status.min)
		op = ps_calculate_rotation1(node_b, status.max);
	else
		op = ps_calculate_rotation2(node_a->nb, node_b);
	if (op < 0)
		while (deep-- > 0 && op < 0)
			op++;
	op = ft_abs(op) + ft_abs(deep) + 1;
	if (op < status.op)
	{
		status.op = op;
		status.pos = pos;
	}
	return (ps_calculate_op(node_a->prev, node_b, status, deep + 1));
}
