/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:59 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:12:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_n	*ft_stack_peek(t_stack *stack)
{
	return (ft_dcll_peekfront(stack));
}

t_stack_n	*ft_stack_pop(t_stack *stack)
{
	return (ft_dcll_popfront(stack));
}

void	ft_stack_clear(t_stack *stack)
{
	ft_dcll_clear(stack);
}
