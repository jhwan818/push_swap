/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:10:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:10:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

t_dcll_n	*ft_dcll_peekfront(t_dcll *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->front);
}

t_dcll_n	*ft_dcll_peekrear(t_dcll *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->rear);
}
