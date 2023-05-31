/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 15:49:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_action3(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == RRA)
	{
		ps_reverse_rotate(stack_a);
		return ("rra ");
	}
	else if (op == RRB)
	{
		ps_reverse_rotate(stack_b);
		return ("rrb ");
	}
	else if (op == RRR)
	{
		ps_reverse_rotate(stack_a);
		ps_reverse_rotate(stack_b);
		return ("rrr ");
	}
	else
		return (NULL);
}
char	*ps_action2(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == PB)
	{
		if (ps_push(stack_b, stack_a) == ERR)
			return (NULL);
		return ("pb ");
	}
	else if (op == RA)
	{
		ps_rotate(stack_a);
		return ("ra ");
	}
	else if (op == RB)
	{
		ps_rotate(stack_b);
		return ("rb ");
	}
	else if (op == RR)
	{
		ps_rotate(stack_a);
		ps_rotate(stack_b);
		return ("rr ");
	}
	else
		return (ps_action3(stack_a, stack_b, op));
}
char	*ps_action(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == SA)
	{
		ps_swap(stack_a);
		return ("sa ");
	}
	else if (op == SB)
	{
		ps_swap(stack_b);
		return ("sb ");
	}
	else if (op == SS)
	{
		ps_swap(stack_a);
		ps_swap(stack_b);
		return ("ss ");
	}
	else if (op == PA)
	{
		if (ps_push(stack_a, stack_b) == ERR)
			return (NULL);
		return ("pa ");
	}
	else
		return (ps_action2(stack_a, stack_b, op));
}
