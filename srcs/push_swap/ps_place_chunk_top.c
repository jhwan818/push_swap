/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_place_chunk_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:56:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 21:14:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_place_chunk_top(t_stack *stack_a, t_stack *stack_b, \
		t_chunk *chunk, t_buff *buff)
{
	size_t	i;

	i = 0;
	while (i < chunk[0].len && i < chunk[1].len)
	{
		ps_action(stack_a, stack_b, RRR, buff);
		i++;
	}
	while (i < chunk[0].len)
	{
		ps_action(stack_a, stack_b, RRA, buff);
		i++;
	}
	while (i < chunk[1].len)
	{
		ps_action(stack_a, stack_b, RRB, buff);
		i++;
	}
}
