/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_len2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:38:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/13 18:30:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_len2(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	ps_sort_len2_a(stack_a, stack_b, buff);
}

void	ps_sort_len2_a(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	if (stack_a->front->nb > stack_a->front->next->nb)
		ps_action(stack_a, stack_b, SA, buff);
}

void	ps_sort_len2_b(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	if (stack_b->front->nb < stack_b->front->next->nb)
		ps_action(stack_a, stack_b, SB, buff);
	ps_action(stack_a, stack_b, PA, buff);
	ps_action(stack_a, stack_b, PA, buff);
}
