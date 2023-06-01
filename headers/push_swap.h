/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/02 00:34:09 by junghwle         ###   ########.fr       */
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
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9
# define PA 10
# define PB 11

void		ps_free_staks(t_stack *stack_a, t_stack *stack_b);
void		ps_err_exit(void);

int			ps_parse_input(t_stack *stack_a, t_stack *stack_b, \
		int ac, char **av);

void		ps_action(t_stack *stack_a, t_stack *stack_b, t_op op);
void		ps_swap(t_stack *stack);
void		ps_push(t_stack *stack_dst, t_stack *stack_src);
void		ps_rotate(t_stack *stack);
void		ps_reverse_rotate(t_stack *stack);

typedef struct s_status
{
	int		max;
	int		min;
	size_t	pos;
	int		op;
}						t_status;

void		ps_sort_three(t_stack *stack_a, t_stack *stack_b);
void		ps_sort(t_stack *stack_a, t_stack *stack_b);
t_status	ps_calculate_op(t_stack_n *node_a, t_stack_n *node_b, \
		t_status status, int deep);
t_status	ps_calculate_op_rev(t_stack_n *node_a, t_stack_n *node_b, \
		t_status status, int deep);
int			ps_calculate_rotation1(t_stack_n *node_b, int max);
int			ps_calculate_rotation2(int nb, t_stack_n *node_b);
void		insert2(t_stack *stack_a, t_stack *stack_b, \
		t_status *status, int min);
void		insert1(t_stack *stack_a, t_stack *stack_b, \
		t_status *status, int min);

void		ps_console(t_stack *stack_a, t_stack *stack_b);
void		ps_show_stack(t_stack *stack_a, t_stack *stack_b);

#endif
