/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divide_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:46:29 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 01:31:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_divide_chunk_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	size_t	i;

	i = 0;
	while (i < chunk.len)
	{
		if (stack_a->front->nb < chunk.pv1)
		{
			ps_action(stack_a, stack_b, PB, buff);
			ps_action(stack_a, stack_b, RB, buff);
		}
		else if (stack_a->front->nb < chunk.pv2)
			ps_action(stack_a, stack_b, PB, buff);
		else
			ps_action(stack_a, stack_b, RA, buff);
		i++;
	}
}

void	ps_divide_chunk_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	size_t	i;

	i = 0;
	while (i < chunk.len)
	{
		if (stack_b->front->nb < chunk.pv1)
		{
			ps_action(stack_a, stack_b, PA, buff);
			ps_action(stack_a, stack_b, RA, buff);
		}
		else if (stack_b->front->nb < chunk.pv2)
			ps_action(stack_a, stack_b, RB, buff);
		else
			ps_action(stack_a, stack_b, PA, buff);
		i++;
	}
}

