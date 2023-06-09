/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:07:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 23:00:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ps_quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	chunk_pack[2];
	t_chunk	new_chunk1;
	t_chunk	new_chunk2;
	t_chunk	new_chunk3;

	char	a;
	ps_show_stack(stack_a, stack_b);
	scanf("%c", &a);

	if (chunk.len >= 4)
	{
		printf("div A\n");
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
	else
	{
		printf("sort A\n");
		ps_sort_chunk_a(stack_a, stack_b, chunk.len, buff);
	}
}

void	ps_quick_sort_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	chunk_pack[2];
	t_chunk	new_chunk1;
	t_chunk	new_chunk2;
	t_chunk	new_chunk3;

	char	a;
	ps_show_stack(stack_a, stack_b);
	scanf("%c", &a);

	if (chunk.len >= 4)
	{
		printf("sort B\n");
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
	else
	{
		printf("sort B\n");
		ps_sort_chunk_b(stack_a, stack_b, chunk.len, buff);
	}
}
