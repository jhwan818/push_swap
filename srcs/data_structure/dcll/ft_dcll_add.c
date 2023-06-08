/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

static void	ft_dcll_setlink(t_dcll *list, t_dcll_n *newnode)
{
	list->rear->next = newnode;
	list->front->prev = newnode;
	newnode->next = list->front;
	newnode->prev = list->rear;
}

t_dcll_n	*ft_dcll_addfront(t_dcll *list, int nb)
{
	t_dcll_n	*newnode;

	newnode = ft_dcll_newnode(nb);
	if (newnode == NULL)
		return (NULL);
	if (list->size == 0)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		list->front = newnode;
		list->rear = newnode;
	}
	else
	{
		ft_dcll_setlink(list, newnode);
		list->front = newnode;
	}
	list->size++;
	return (newnode);
}

t_dcll_n	*ft_dcll_addrear(t_dcll *list, int nb)
{
	t_dcll_n	*newnode;

	newnode = ft_dcll_newnode(nb);
	if (newnode == NULL)
		return (NULL);
	if (list->size == 0)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		list->front = newnode;
		list->rear = newnode;
	}
	else
	{
		ft_dcll_setlink(list, newnode);
		list->rear = newnode;
	}
	list->size++;
	return (newnode);
}
