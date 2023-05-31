/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:12:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_push(t_stack *stack_dst, t_stack *stack_src)
{
	t_stack_n	*node;

	if (stack_src->size == 0)
		return (0);
	node = ft_stack_pop(stack_src);
	if (ft_stack_push_node(stack_dst, node) == NULL)
		return (ERR);
	return (1);
}
