/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:11:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/17 18:34:23 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ch_parse_action3(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[2] == '\n' && ft_strlen(line) != 3)
		return (NULL);
	else if (line[2] == '\n')
		return (ps_action(stack_a, stack_b, RR, NULL));
	else if (line[3] != '\n' || ft_strlen(line) != 4)
		return (NULL);
	else if (line[2] == 'a')
		return (ps_action(stack_a, stack_b, RRA, NULL));
	else if (line[2] == 'b')
		return (ps_action(stack_a, stack_b, RRB, NULL));
	else if (line[2] == 'r')
		return (ps_action(stack_a, stack_b, RRR, NULL));
	else
		return (NULL);
}

static char	*ch_parse_action2(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[0] == 'p')
	{
		if (line[2] != '\n' || ft_strlen(line) != 3)
			return (NULL);
		if (line[1] == 'a')
			return (ps_action(stack_a, stack_b, PA, NULL));
		else if (line[1] == 'b')
			return (ps_action(stack_a, stack_b, PB, NULL));
		else
			return (NULL);
	}
	else if (line[0] == 'r')
	{
		if (line[1] == 'a')
			return (ps_action(stack_a, stack_b, RA, NULL));
		else if (line[1] == 'b')
			return (ps_action(stack_a, stack_b, RB, NULL));
		else
			return (ch_parse_action3(stack_a, stack_b, line));
	}
	else
		return (NULL);
}

static char	*ch_parse_action(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[0] == 's')
	{
		if (line[2] != '\n' || ft_strlen(line) != 3)
			return (NULL);
		else if (line[1] == 'a')
			return (ps_action(stack_a, stack_b, SA, NULL));
		else if (line[1] == 'b')
			return (ps_action(stack_a, stack_b, SB, NULL));
		else if (line[1] == 's')
			return (ps_action(stack_a, stack_b, SS, NULL));
		else
			return (NULL);
	}
	else
		return (ch_parse_action2(stack_a, stack_b, line));
}

static void	ch_err_exit(t_stack *stack_a, t_stack *stack_b, char *line)
{
	free(line);
	while (line != NULL)
	{
		line = get_next_line(STDIN);
		free(line);
	}
	ps_err_exit(stack_a, stack_b);
}

void	ch_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(STDIN);
	while (line != NULL)
	{
		if (ft_strlen(line) > 4)
			ch_err_exit(stack_a, stack_b, line);
		if (ch_parse_action(stack_a, stack_b, line) == NULL)
			ch_err_exit(stack_a, stack_b, line);
		free(line);
		line = get_next_line(STDIN);
	}
	free(line);
}
