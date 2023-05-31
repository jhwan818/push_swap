/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:40:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_print_description(void)
{
	ft_printf("Select action >>\n\n");
	ft_printf("SA  = %d\t\t", SA);
	ft_printf("SB  = %d\t\t", SB);
	ft_printf("SS  = %d\n", SS);
	ft_printf("PA  = %d\t\t", PA);
	ft_printf("PB  = %d\n", PB);
	ft_printf("RA  = %d\t\t", RA);
	ft_printf("RB  = %d\t\t", RB);
	ft_printf("RR  = %d\n", RR);
	ft_printf("RRA = %d\t\t", RRA);
	ft_printf("RRB = %d\t", RRB);
	ft_printf("RRR = %d\n", RRR);
}

static t_op	ps_get_input(void)
{
	char	input[100];

	ps_print_description();
	ft_printf("\n");
	read(0, &input, 100);
	return ((t_op)ft_atoi(input));
}

static int	ps_select_action2(t_stack *stack_a, t_stack *stack_b, t_op input)
{
	if (input == RA)
		ps_rotate(stack_a);
	else if (input == RB)
		ps_rotate(stack_b);
	else if (input == RR)
	{
		ps_rotate(stack_a);
		ps_rotate(stack_b);
	}
	else if (input == RRA)
		ps_reverse_rotate(stack_a);
	else if (input == RRB)
		ps_reverse_rotate(stack_b);
	else if (input == RRR)
	{
		ps_reverse_rotate(stack_a);
		ps_reverse_rotate(stack_b);
	}
	else if (input == -1)
		return (-1);
	return (0);
}

static int	ps_select_action(t_stack *stack_a, t_stack *stack_b, t_op input)
{
	if (input == SA)
		ps_swap(stack_a);
	else if (input == SB)
		ps_swap(stack_b);
	else if (input == SS)
	{
		ps_swap(stack_a);
		ps_swap(stack_b);
	}
	else if (input == PA)
		ps_push(stack_a, stack_b);
	else if (input == PB)
		ps_push(stack_b, stack_a);
	else
		return (ps_select_action2(stack_a, stack_b, input));
	return (0);
}

void	ps_console(t_stack *stack_a, t_stack *stack_b)
{
	ps_show_stack(stack_a, stack_b);
	printf("\n");
	while (ps_select_action(stack_a, stack_b, ps_get_input()) != -1)
	{
		ps_show_stack(stack_a, stack_b);
		printf("\n");
	}
	ps_show_stack(stack_a, stack_b);
}
