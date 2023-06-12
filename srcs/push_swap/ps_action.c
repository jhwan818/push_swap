/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/12 23:00:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ps_action2(t_stack *stack_a, t_stack *stack_b, t_op op);
static char	*ps_action3(t_stack *stack_a, t_stack *stack_b, t_op op);
static char	*ps_action4(t_stack *stack_a, t_stack *stack_b, t_op op);

char	*ps_action(t_stack *stack_a, t_stack *stack_b, t_op op, t_buff *buff)
{
	char	*op_char;

	op_char = ps_action2(stack_a, stack_b, op);
	ft_strlcat(&buff->b[buff->curlen], op_char, 5);
	buff->curlen += ft_strlen(op_char);
	return (op_char);
}

char	*ps_action2(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == SA)
	{
		ps_swap(stack_a);
		return ("sa\n");
	}
	else if (op == SB)
	{
		ps_swap(stack_b);
		return ("sb\n");
	}
	else if (op == SS)
	{
		ps_swap(stack_a);
		ps_swap(stack_b);
		return ("ss\n");
	}
	else if (op == PA)
	{
		ps_push(stack_a, stack_b);
		return ("pa\n");
	}
	else
		return (ps_action3(stack_a, stack_b, op));
}

static char	*ps_action3(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == PB)
	{
		ps_push(stack_b, stack_a);
		return ("pb\n");
	}
	else if (op == RA)
	{
		ps_rotate(stack_a);
		return ("ra\n");
	}
	else if (op == RB)
	{
		ps_rotate(stack_b);
		return ("rb\n");
	}
	else if (op == RR)
	{
		ps_rotate(stack_a);
		ps_rotate(stack_b);
		return ("rr\n");
	}
	else
		return (ps_action4(stack_a, stack_b, op));
}

static char	*ps_action4(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	if (op == RRA)
	{
		ps_reverse_rotate(stack_a);
		return ("rra\n");
	}
	else if (op == RRB)
	{
		ps_reverse_rotate(stack_b);
		return ("rrb\n");
	}
	else if (op == RRR)
	{
		ps_reverse_rotate(stack_a);
		ps_reverse_rotate(stack_b);
		return ("rrr\n");
	}
	else
		ps_err_exit(stack_a, stack_b);
	return (NULL);
}
