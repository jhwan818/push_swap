/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:09:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/01 23:31:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_calculate_rotation1(t_stack_n *node_b, int max)
{
	t_stack_n	*tmp;
	int			r;
	int			rr;

	r = 0;
	tmp = node_b;
	while (tmp->nb != max)
	{
		tmp = tmp->next;
		r++;
	}
	rr = 0;
	tmp = node_b;
	while (tmp->nb != max)
	{
		tmp = tmp->prev;
		rr--;
	}
	if (ft_abs(r) < ft_abs(rr))
		return (r);
	else
		return (rr);
}

int	ps_calculate_rotation2(int nb, t_stack_n *node_b)
{
	t_stack_n	*tmp;
	int			r;
	int			rr;

	r = 0;
	tmp = node_b;
	while ((tmp->nb > nb) || (tmp->prev->nb < nb))
	{
		tmp = tmp->next;
		r++;
	}
	rr = 0;
	tmp = node_b;
	while ((tmp->nb > nb) || (tmp->prev->nb < nb))
	{
		tmp = tmp->prev;
		rr--;
	}
	return (ft_min(r, rr));
}
