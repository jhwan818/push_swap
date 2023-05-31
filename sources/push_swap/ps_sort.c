/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:13:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void state1(t_stack *stack_a, t_stack *stack_b, char *ret)
{
	stack_a = NULL;
	stack_b = NULL;
	ret = NULL;
}

static void	state0(t_stack *stack_a, t_stack *stack_b, char *ret)
{
	t_stack_n	*node;

	node = ft_stack_peek(stack_a);
	if (node->nb > node->next->nb)
		ft_strlcat(ret, ps_action(stack_a, stack_b, SA), ft_strlen(ret) + 4);
	ft_strlcat(ret, ps_action(stack_a, stack_b, RRA), ft_strlen(ret) + 4);
	ft_printf("%s", ret);
	state1(stack_a, stack_b, ret);
}

char	*ps_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 40000);
	ret[0] = '\0';
	state0(stack_a, stack_b, ret);
	return (NULL);
}
