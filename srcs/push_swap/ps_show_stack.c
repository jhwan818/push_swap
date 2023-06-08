/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_show_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 14:53:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_itr_stack(t_stack_n *node_a, t_stack_n *node_b, \
	size_t size_a, size_t size_b);

void	ps_show_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_n	*node_a;
	t_stack_n	*node_b;

	node_a = ft_stack_peek(stack_a);
	node_b = ft_stack_peek(stack_b);
	ft_printf("  STACK_A         STACK_B\n");
	print_itr_stack(node_a, node_b, stack_a->size, stack_b->size);
}

static void	print_itr_stack(t_stack_n *node_a, t_stack_n *node_b, \
	size_t size_a, size_t size_b)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < size_a || j < size_b)
	{
		if (i < size_a)
		{
			ft_printf("|% -15d", node_a->nb);
			i++;
			if (j >= size_b)
				ft_printf("|%-15c |\n", ' ');
			node_a = node_a->next;
		}
		if (j < size_b)
		{
			if (i >= size_a && i <= j)
				ft_printf("|%-15c", ' ');
			ft_printf("|% -15d |\n", node_b->nb);
			j++;
			node_b = node_b->next;
		}
	}
}
