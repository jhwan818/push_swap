/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:45 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

static void	ft_dcll_setlink(t_dcll_n *retnode)
{
	retnode->next->prev = retnode->prev;
	retnode->prev->next = retnode->next;
	retnode->next = NULL;
	retnode->prev = NULL;
}

t_dcll_n	*ft_dcll_popfront(t_dcll *list)
{
	t_dcll_n	*retnode;

	if (list->size == 0)
		return (NULL);
	retnode = list->front;
	list->front = retnode->next;
	ft_dcll_setlink(retnode);
	list->size--;
	if (list->size == 0)
	{
		list->front = NULL;
		list->rear = NULL;
	}
	return (retnode);
}

t_dcll_n	*ft_dcll_poprear(t_dcll *list)
{
	t_dcll_n	*retnode;

	if (list->size == 0)
		return (NULL);
	retnode = list->rear;
	list->rear = retnode->prev;
	ft_dcll_setlink(retnode);
	list->size--;
	if (list->size == 0)
	{
		list->front = NULL;
		list->rear = NULL;
	}
	return (retnode);
}
