/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:43:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 19:50:10 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

int	*ft_dcll_to_arr(t_dcll *list)
{
	int			*arr;
	size_t		i;
	t_dcll_n	*node;

	arr = (int *)malloc(sizeof(int) * list->size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	node = list->front;
	while (i < list->size)
	{
		arr[i++] = node->nb;
		node = node->next;
	}
	return (arr);
}
