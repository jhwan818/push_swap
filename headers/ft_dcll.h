/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcll.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:31 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:44:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DCLL_H
# define FT_DCLL_H

# include <stdlib.h>

typedef struct s_dcll_node
{
	int					nb;
	struct s_dcll_node	*next;
	struct s_dcll_node	*prev;
}	t_dcll_n;

typedef struct s_ldcll
{
	t_dcll_n	*front;
	t_dcll_n	*rear;
	size_t		size;
}	t_dcll;

t_dcll		*ft_dcll_init(void);
t_dcll_n	*ft_dcll_newnode(int nb);
t_dcll_n	*ft_dcll_addfront(t_dcll *list, int nb);
t_dcll_n	*ft_dcll_addrear(t_dcll *list, int nb);
t_dcll_n	*ft_dcll_peekfront(t_dcll *list);
t_dcll_n	*ft_dcll_peekrear(t_dcll *list);
t_dcll_n	*ft_dcll_popfront(t_dcll *list);
t_dcll_n	*ft_dcll_poprear(t_dcll *list);
void		ft_dcll_clear(t_dcll *list);

#endif
