/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:20:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 23:00:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_chunk_a(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff)
{
	if (len == 2)
		ps_sort_len2_a(stack_a, stack_b, buff);
	else if (len == 3)
	{
		ps_sort_len3_a(stack_a, stack_b, buff);
		ps_sort_len3_a(stack_a, stack_b, buff);
	}
	//else if (len == 4)
	//	ps_sort_len4_a(stack_a, stack_b, buff);
	//else if (len == 5)
	//	ps_sort_len5_a(stack_a, stack_b, buff);
}

void	ps_sort_chunk_b(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff)
{
	if (len == 1)
		ps_action(stack_a, stack_b, PA, buff);
	else if (len == 2)
		ps_sort_len2_b(stack_a, stack_b, buff);
	else if (len == 3)
		ps_sort_len3_b(stack_a, stack_b, buff);
	//else if (len == 4)
	//	ps_sort_len4_b(stack_a, stack_b, buff);
	//else if (len == 5)
	//	ps_sort_len5_b(stack_a, stack_b, buff);
}
