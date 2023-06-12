/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:09:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/12 23:52:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_init_chunk(t_chunk *chunk, t_stack *stack)
{
	chunk->arr = ft_stack_to_arr(stack);
	chunk->min_i = 0;
	chunk->max_i = stack->size - 1;
	chunk->len = stack->size;
	ft_merge_sort(chunk->arr, 0, chunk->len - 1);
	chunk->pv1 = chunk->arr[chunk->len / 3];
	chunk->pv2 = chunk->arr[(chunk->len * 2) / 3];
}

static void ps_sort_short(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	if (stack_a->size == 2)
		ps_sort_len2(stack_a, stack_b, buff);
	else if (stack_a->size == 3)
		ps_sort_len3(stack_a, stack_b, buff);
}

void	ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	t_buff	buff;

	ps_init_chunk(&chunk, stack_a);
	buff.b[0] = '\0';
	buff.curlen = 0;
	buff.maxlen = stack_a->size * 100;
	if (chunk.len <= 3)
		ps_sort_short(stack_a, stack_b, &buff);
	else
		ps_quick_sort_a(stack_a, stack_b, chunk, &buff);
	if (ps_flush_buff(buff.b) == -1)
		ps_err_exit(stack_a, stack_b);
}
