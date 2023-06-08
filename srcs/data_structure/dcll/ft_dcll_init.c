/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:49 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

t_dcll	*ft_dcll_init(void)
{
	t_dcll	*list;

	list = (t_dcll *)malloc(sizeof(t_dcll));
	if (list == NULL)
		return (NULL);
	list->front = NULL;
	list->rear = NULL;
	list->size = 0;
	return (list);
}
