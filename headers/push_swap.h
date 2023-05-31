/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 15:50:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_stack.h"
# include "libft.h"
# include "ft_printf.h"

# define STDOUT 1
# define STDERR 2
# define ERR -1

# define MAX_INT_RANGE 4294967296
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef unsigned char	t_bool;
# define TRUE 1
# define FALSE 0

/*OPERATIONS*/
typedef char			t_op;
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

void	ps_free_staks(t_stack *stack_a, t_stack *stack_b);
void	ps_err_exit(void);

int		ps_parse_input(t_stack *stack_a, int ac, char **av);

char	*ps_action(t_stack *stack_a, t_stack *stack_b, t_op op);
void	ps_swap(t_stack *stack);
int		ps_push(t_stack *stack_dst, t_stack *stack_src);
void	ps_rotate(t_stack *stack);
void	ps_reverse_rotate(t_stack *stack);

char	*ps_sort(t_stack *stack_a, t_stack *stack_b);

void	ps_console(t_stack *stack_a, t_stack *stack_b);
void	ps_show_stack(t_stack *stack_a, t_stack *stack_b);

#endif
