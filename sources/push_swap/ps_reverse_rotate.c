/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:13:10 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 15:47:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse_rotate(t_stack *stack)
{
	stack->rear = stack->rear->prev;
	stack->front = stack->rear->next;
}
