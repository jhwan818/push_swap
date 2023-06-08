/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:07:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 01:36:23 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

void	ps_quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	new_chunk;

	//char	a;
	//ps_show_stack(stack_a, stack_b);
	//scanf("%c", &a);
	
	if (chunk.len >= 3)
	{
	//	printf("div A\n");
		ps_divide_chunk_a(stack_a, stack_b, chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 1);
		ps_place_chunk_top_a(stack_a, stack_b, new_chunk, buff);
		ps_quick_sort_a(stack_a, stack_b, new_chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 2);
		ps_quick_sort_b(stack_a, stack_b, new_chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 3);
		ps_place_chunk_top_b(stack_a, stack_b, new_chunk, buff);
		ps_quick_sort_b(stack_a, stack_b, new_chunk, buff);
	}
	else if (chunk.len == 2)
	{
	//	printf("sort A\n");
		ps_sort_len2_a(stack_a, stack_b, buff);
	}
	//else
	//{
	//	printf("sort A\n");
	//}
}

void	ps_quick_sort_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff)
{
	t_chunk	new_chunk;

	//char	a;
	//ps_show_stack(stack_a, stack_b);
	//scanf("%c", &a);

	if (chunk.len >= 3)
	{
	//	printf("div B\n");
		ps_divide_chunk_b(stack_a, stack_b, chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 1);
		ps_quick_sort_a(stack_a, stack_b, new_chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 2);
		ps_place_chunk_top_b(stack_a, stack_b, new_chunk, buff);
		ps_quick_sort_b(stack_a, stack_b, new_chunk, buff);
		ps_set_chunk(&new_chunk, &chunk, 3);
		ps_place_chunk_top_a(stack_a, stack_b, new_chunk, buff);
		ps_quick_sort_a(stack_a, stack_b, new_chunk, buff);
	}
	else if (chunk.len == 2)
	{
	//	printf("sort B\n");
		ps_sort_len2_b(stack_a, stack_b, buff);
	}
	else
	{
	//	printf("sort B\n");
		ps_action(stack_a, stack_b, PA, buff);
	}
}
