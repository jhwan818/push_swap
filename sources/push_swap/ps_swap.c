/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:13:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:37:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_swap(t_stack *stack)
{
	t_stack_n	*node1;
	t_stack_n	*node2;
	int			tmp;

	if (stack->size < 2)
		return (0);
	node1 = ft_stack_peek(stack);
	node2 = node1->next;
	tmp = node1->nb;
	node1->nb = node2->nb;
	node2->nb = tmp;
	return (1);
}
