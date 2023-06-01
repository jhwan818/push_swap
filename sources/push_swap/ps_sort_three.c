/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:31:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/02 00:38:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_n	*node;

	node = ft_stack_peek(stack_a);
	if (node->nb < node->next->nb && node->next->nb > node->prev->nb && \
			node->prev->nb > node->nb)
		ps_action(stack_a, stack_b, SA);
	else if (node->nb > node->next->nb && node->next->nb < node->prev->nb && \
			node->prev->nb > node->nb)
		ps_action(stack_a, stack_b, SA);
	else if (node->nb < node->next->nb && node->next->nb > node->prev->nb && \
			node->prev->nb < node->nb)
		ps_action(stack_a, stack_b, RRA);
	else if (node->nb > node->next->nb && node->next->nb < node->prev->nb && \
			node->prev->nb < node->nb)
		ps_action(stack_a, stack_b, RA);
	else if (node->nb > node->next->nb && node->next->nb > node->prev->nb && \
			node->prev->nb < node->nb)
		ps_action(stack_a, stack_b, SA);
	else
		return ;
	ps_sort_three(stack_a, stack_b);
}
