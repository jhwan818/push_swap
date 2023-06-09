/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_len3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:24:53 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/09 21:56:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_len3_a(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	t_stack_n	*n1;
	t_stack_n	*n2;
	t_stack_n	*n3;

	n1 = ft_stack_peek(stack_a);
	n2 = n1->next;
	n3 = n2->next;
	if (n1->nb < n2->nb && n1->nb < n3->nb && n2->nb > n3->nb)
	{
		ps_action(stack_a, stack_b, RA, buff);
		ps_action(stack_a, stack_b, SA, buff);
		ps_action(stack_a, stack_b, RRA, buff);
	}
	else if (n1->nb > n2->nb && n1->nb < n3->nb && n2->nb < n3->nb)
		ps_action(stack_a, stack_b, SA, buff);
	else if (n1->nb < n2->nb && n1->nb > n3->nb && n2->nb > n3->nb)
	{
		ps_action(stack_a, stack_b, RA, buff);
		ps_action(stack_a, stack_b, SA, buff);
		ps_action(stack_a, stack_b, RRA, buff);
	}
	else if (n1->nb > n2->nb && n1->nb > n3->nb && n2->nb < n3->nb)
		ps_action(stack_a, stack_b, SA, buff);
	else if (n1->nb > n2->nb && n1->nb > n3->nb && n2->nb > n3->nb)
		ps_action(stack_a, stack_b, SA, buff);
}

static void	ps_sort_len3_b2(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	t_stack_n	*n1;
	t_stack_n	*n2;
	t_stack_n	*n3;

	n1 = ft_stack_peek(stack_a);
	n2 = n1->next;
	n3 = n2->next;
	if (n1->nb > n2->nb && n1->nb < n3->nb && n2->nb < n3->nb)
	{
		ps_action(stack_a, stack_b, RB, buff);
		ps_action(stack_a, stack_b, SA, buff);
		ps_action(stack_a, stack_b, PA, buff);
		ps_action(stack_a, stack_b, RRB, buff);
		ps_sort_len2_b(stack_a, stack_b, buff);
	}
	else if (n1->nb < n2->nb && n1->nb < n3->nb && n2->nb > n3->nb)
	{
		ps_action(stack_a, stack_b, SB, buff);
		ps_action(stack_a, stack_b, PA, buff);
		ps_sort_len2_b(stack_a, stack_b, buff);
	}
	else
	{
		ps_action(stack_a, stack_b, PA, buff);
		ps_sort_len2_b(stack_a, stack_b, buff);
	}
}

void	ps_sort_len3_b(t_stack *stack_a, t_stack *stack_b, t_buff *buff)
{
	t_stack_n	*n1;
	t_stack_n	*n2;
	t_stack_n	*n3;

	n1 = ft_stack_peek(stack_a);
	n2 = n1->next;
	n3 = n2->next;
	if (n1->nb < n2->nb && n1->nb < n3->nb && n2->nb < n3->nb)
	{
		ps_action(stack_a, stack_b, RB, buff);
		ps_action(stack_a, stack_b, PA, buff);
		ps_action(stack_a, stack_b, PA, buff);
		ps_action(stack_a, stack_b, SA, buff);
		ps_action(stack_a, stack_b, RRB, buff);
		ps_action(stack_a, stack_b, PA, buff);
	}
	else if (n1->nb < n2->nb && n1->nb < n3->nb && n2->nb > n3->nb)
	{
		ps_action(stack_a, stack_b, SB, buff);
		ps_action(stack_a, stack_b, PA, buff);
		ps_sort_len2_b(stack_a, stack_b, buff);
	}
	else
		ps_sort_len3_b2(stack_a, stack_b, buff);
}
