/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:22:10 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/17 18:35:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_issorted_a(t_stack *stack_a, size_t len)
{
	t_stack_n	*node;
	size_t		i;

	i = 0;
	node = ft_stack_peek(stack_a);
	while (node->next != NULL && i < len - 1)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	ps_issorted_b(t_stack *stack_b, size_t len)
{
	t_stack_n	*node;
	size_t		i;

	i = 0;
	node = ft_stack_peek(stack_b);
	while (node->next != NULL && i < len - 1)
	{
		if (node->nb < node->next->nb)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
