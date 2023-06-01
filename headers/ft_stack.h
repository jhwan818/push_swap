/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/01 18:43:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_dcll.h"

typedef t_dcll_n	t_stack_n;
typedef t_dcll		t_stack;

t_stack		*ft_stack_init(void);
t_stack_n	*ft_stack_push(t_stack *stack, int nb);
t_stack_n	*ft_stack_push_node(t_stack *stack, t_stack_n *node);
t_stack_n	*ft_stack_peek(t_stack *stack);
t_stack_n	*ft_stack_pop(t_stack *stack);
void		ft_stack_clear(t_stack *stack);
#endif
