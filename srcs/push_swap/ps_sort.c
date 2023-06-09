/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:09:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 21:12:40 by junghwle         ###   ########.fr       */
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

void	ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	t_buff	buff;

	ps_init_chunk(&chunk, stack_a);
	buff.b = (char *)malloc(sizeof(char) * stack_a->size * 100);
	if (buff.b == NULL)
		ps_err_exit(stack_a, stack_b);
	buff.curlen = 0;
	buff.maxlen = stack_a->size * 100;
	ps_quick_sort_a(stack_a, stack_b, chunk, &buff);
	ft_printf("%s", buff.b);
	free(buff.b);
}
