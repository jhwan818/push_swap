/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:25:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 21:15:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_set_chunk(t_chunk *new_chunk, t_chunk *old_chunk, int num)
{
	new_chunk->arr = old_chunk->arr;
	if (num == 1)
	{
		new_chunk->min_i = old_chunk->min_i + (old_chunk->len * 2) / 3;
		new_chunk->max_i = old_chunk->max_i;
	}
	else if (num == 2)
	{
		new_chunk->min_i = old_chunk->min_i + old_chunk->len / 3;
		new_chunk->max_i = old_chunk->min_i + (old_chunk->len * 2) / 3 - 1;
	}
	else
	{
		new_chunk->min_i = old_chunk->min_i;
		new_chunk->max_i = old_chunk->min_i + old_chunk->len / 3 - 1;
	}
	new_chunk->len = new_chunk->max_i - new_chunk->min_i + 1;
	new_chunk->pv1 = new_chunk->arr[new_chunk->len / 3 + new_chunk->min_i];
	new_chunk->pv2 = new_chunk->arr[(new_chunk->len * 2) / 3 + \
						new_chunk->min_i];
}
