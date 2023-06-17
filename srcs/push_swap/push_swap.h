/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/17 17:35:30 by junghwle         ###   ########.fr       */
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

typedef struct s_buff
{
	char	*b;
	size_t	curlen;
	size_t	maxlen;
}	t_buff;

typedef struct s_chunk
{
	int		*arr;
	size_t	min_i;
	size_t	max_i;
	size_t	len;
	int		pv1;
	int		pv2;
}	t_chunk;

void	ps_free_staks(t_stack *stack_a, t_stack *stack_b);
void	ps_err_exit(t_stack *stack_a, t_stack *stack_b);

int		ps_parse_input(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

char	*ps_action(t_stack *stack_a, t_stack *stack_b, t_op op, t_buff *buff);
void	ps_swap(t_stack *stack);
void	ps_push(t_stack *stack_dst, t_stack *stack_src);
void	ps_rotate(t_stack *stack);
void	ps_reverse_rotate(t_stack *stack);

void	ps_sort(t_stack *stack_a, t_stack *stack_b);
void	ps_set_chunk(t_chunk *new_chunk, t_chunk *old_chunk, int num);
void	ps_divide_chunk_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff);
void	ps_divide_chunk_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff);
void	ps_quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff);
void	ps_quick_sort_b(t_stack *stack_a, t_stack *stack_b, \
		t_chunk chunk, t_buff *buff);
void	ps_place_chunk_top(t_stack *stack_a, t_stack *stack_b, \
		t_chunk *chunk, t_buff *buff);

void	ps_sort_chunk_a(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff);
void	ps_sort_chunk_b(t_stack *stack_a, t_stack *stack_b, \
		size_t len, t_buff *buff);
int		ps_issorted_a(t_stack *stack_a, size_t len);
int		ps_issorted_b(t_stack *stack_b, size_t len);
void	ps_sort_len2(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len2_a(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len2_b(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len3(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len3_a(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len3_b(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len4(t_stack *stack_a, t_stack *stack_b, t_buff *buff);
void	ps_sort_len5(t_stack *stack_a, t_stack *stack_b, t_buff *buff);

int		ps_flush_buff(const char *buffer);

void	ps_console(t_stack *stack_a, t_stack *stack_b);
void	ps_show_stack(t_stack *stack_a, t_stack *stack_b);

#endif
