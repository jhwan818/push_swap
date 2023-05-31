/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:13:19 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:40:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_atoi_check(t_stack *stack_a, char *nba)
{
	long long	nb;
	long long	sign;

	nb = 0;
	sign = 1;
	if (*nba == '+')
		nba++;
	else if (*nba == '-')
	{
		sign = -1;
		nba++;
	}
	while (ft_isdigit(*nba) && nb < 1000000000)
	{
		nb *= 10;
		nb += (long long)(*nba - '0');
		nba++;
	}
	nb *= sign;
	if (*nba != '\0' || nb < INT_MIN || nb > INT_MAX)
		return (NULL);
	return (ft_stack_push(stack_a, (int)nb));
}

static int	ps_push_numbers(t_stack *stack_a, char **split)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (split[i] != NULL)
	{
		if (ft_atoi_check(stack_a, split[i]) == NULL)
		{
			ret = ERR;
			break ;
		}
		free(split[i]);
		i++;
	}
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	return (ret);
}

int	ps_check_rep(t_stack *stack_a)
{
	size_t		i;
	int			nb;
	t_stack_n	*node;

	node = ft_stack_peek(stack_a);
	nb = node->nb;
	i = 1;
	while (i < stack_a->size)
	{
		node = node->next;
		if (node->nb == nb)
			return (ERR);
		i++;
	}
	return (0);
}

int	ps_parse_input(t_stack *stack_a, int ac, char **av)
{
	char	**split;
	int		i;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (split == NULL)
			return (ERR);
		if (ps_push_numbers(stack_a, split) == ERR)
			return (ERR);
		if (ps_check_rep(stack_a) == ERR)
			return (ERR);
		i++;
	}
	return (0);
}
