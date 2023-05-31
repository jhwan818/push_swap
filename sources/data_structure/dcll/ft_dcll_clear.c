/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dcll.h"

void	ft_dcll_clear(t_dcll *list)
{
	while (list->size > 0)
		free(ft_dcll_popfront(list));
}
