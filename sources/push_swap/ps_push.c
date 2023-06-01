/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/02 00:32:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_stack *stack_dst, t_stack *stack_src)
{
	t_stack_n	*node;

	if (stack_src->size > 0)
	{
		node = ft_stack_pop(stack_src);
		ft_stack_push_node(stack_dst, node);
	}
}
