/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_newnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

t_dcll_n	*ft_dcll_newnode(int nb)
{
	t_dcll_n	*newnode;

	newnode = (t_dcll_n *)malloc(sizeof(t_dcll_n));
	if (newnode == NULL)
		return (NULL);
	newnode->nb = nb;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}
