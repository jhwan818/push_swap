/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:39:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	ret1;
	int	ret2;

	ret1 = ps_swap(stack_a);
	ret2 = ps_swap(stack_b);
	if (ret1 == ERR || ret2 == ERR)
		return (ERR);
	else if (ret1 == 0 && ret2 == 0)
		return (0);
	else
		return (1);
}

static int	ps_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
	return (1);
}

static int	ps_reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ps_reverse_rotate(stack_a);
	ps_reverse_rotate(stack_b);
	return (1);
}

int	ps_action(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == SA)
		return (ps_swap(stack_a));
	else if (op == SB)
		return (ps_swap(stack_b));
	else if (op == SS)
		return (ps_swap_ss(stack_a, stack_b));
	else if (op == PA)
		return (ps_push(stack_a, stack_b));
	else if (op == PB)
		return (ps_push(stack_b, stack_a));
	else if (op == RA)
		return (ps_rotate(stack_a));
	else if (op == RB)
		return (ps_rotate(stack_b));
	else if (op == RR)
		return (ps_rotate_rr(stack_a, stack_b));
	else if (op == RRA)
		return (ps_reverse_rotate(stack_a));
	else if (op == RRB)
		return (ps_reverse_rotate(stack_b));
	else if (op == RRR)
		return (ps_reverse_rotate_rrr(stack_a, stack_b));
	else
		return (ERR);
}
