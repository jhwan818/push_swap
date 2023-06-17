/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:07:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/17 16:43:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push_all_chunk(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff);

void	ps_quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	chunk_pack[2];
	t_chunk	new_chunk1;
	t_chunk	new_chunk2;
	t_chunk	new_chunk3;

	if (ps_issorted_a(stack_a, chunk.len))
		return ;
	else if (chunk.len <= 3)
		ps_sort_chunk_a(stack_a, stack_b, chunk.len, buff);
	else
	{
		ps_divide_chunk_a(stack_a, stack_b, chunk, buff);
		ps_set_chunk(&new_chunk1, &chunk, 1);
		ps_set_chunk(&new_chunk2, &chunk, 2);
		ps_set_chunk(&new_chunk3, &chunk, 3);
		chunk_pack[0] = new_chunk1;
		chunk_pack[1] = new_chunk2;
		ps_place_chunk_top(stack_a, stack_b, chunk_pack, buff);
		ps_quick_sort_a(stack_a, stack_b, new_chunk1, buff);
		ps_quick_sort_b(stack_a, stack_b, new_chunk2, buff);
		ps_quick_sort_b(stack_a, stack_b, new_chunk3, buff);
	}
}

void	ps_quick_sort_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	chunk_pack[2];
	t_chunk	new_chunk1;
	t_chunk	new_chunk2;
	t_chunk	new_chunk3;

	if (ps_issorted_b(stack_b, chunk.len))
		ps_push_all_chunk(stack_a, stack_b, chunk.len, buff);
	else if (chunk.len <= 3)
		ps_sort_chunk_b(stack_a, stack_b, chunk.len, buff);
	else
	{
		ps_divide_chunk_b(stack_a, stack_b, chunk, buff);
		ps_set_chunk(&new_chunk1, &chunk, 1);
		ps_set_chunk(&new_chunk2, &chunk, 2);
		ps_set_chunk(&new_chunk3, &chunk, 3);
		chunk_pack[0] = new_chunk2;
		chunk_pack[1] = new_chunk3;
		ps_quick_sort_a(stack_a, stack_b, new_chunk1, buff);
		ps_place_chunk_top(stack_a, stack_b, chunk_pack, buff);
		ps_quick_sort_a(stack_a, stack_b, new_chunk2, buff);
		ps_quick_sort_b(stack_a, stack_b, new_chunk3, buff);
	}
}

static void	ps_push_all_chunk(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ps_action(stack_a, stack_b, PA, buff);
		i++;
	}
}
