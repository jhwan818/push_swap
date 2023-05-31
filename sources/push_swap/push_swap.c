/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:43:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_stack_init();
	if (*stack_a == NULL)
		return (ERR);
	*stack_b = ft_stack_init();
	if (*stack_b == NULL)
	{
		free(*stack_a);
		return (ERR);
	}
	return (0);
}

void	ps_free_staks(t_stack *stack_a, t_stack *stack_b)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	free(stack_a);
	free(stack_b);
	ft_putstr_fd("Error", STDERR);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (ps_initialize_stacks(&stack_a, &stack_b) == ERR)
		ps_free_staks(stack_a, stack_b);
	if (ps_parse_input(stack_a, ac, av) == ERR)
		ps_free_staks(stack_a, stack_b);
	ps_sort(stack_a, stack_b);
	ps_console(stack_a, stack_b);
	ps_free_staks(stack_a, stack_b);
	return (0);
}
