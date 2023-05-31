/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:11:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stack_init(void)
{
	return (ft_dcll_init());
}

t_stack_n	*ft_stack_push(t_stack *stack, int nb)
{
	return (ft_dcll_addfront(stack, nb));
}

static void	ft_stack_setlink(t_stack *stack, t_stack_n *node)
{
	stack->rear->next = node;
	stack->front->prev = node;
	node->next = stack->front;
	node->prev = stack->rear;
}

t_stack_n	*ft_stack_push_node(t_stack *stack, t_stack_n *node)
{
	if (node == NULL)
		return (NULL);
	if (stack->size == 0)
	{
		node->next = node;
		node->prev = node;
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		ft_stack_setlink(stack, node);
		stack->front = node;
	}
	stack->size++;
	return (node);
}
