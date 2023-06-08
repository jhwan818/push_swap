/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:10:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 13:11:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "ft_dcll.h"
#include <stdio.h>

int	main(void)
{
	t_dcll		*list;
	t_dcll_n	*node;

	printf("check init\n");
	list = ft_dcll_init();
	printf("list address -> %p\n", list);

	printf("add front\n");
	node = ft_dcll_addfront(list, 1);
	printf("node address -> %p, value = %d\n", node, node->nb);
	printf("list size -> %lld\n", list->size);
	printf("add rear\n");
	node = ft_dcll_addrear(list, 2);
	printf("node address -> %p, value = %d\n", node, node->nb);
	printf("list size -> %lld\n", list->size);
	printf("add front\n");
	node = ft_dcll_addfront(list, 3);
	printf("node address -> %p, value = %d\n", node, node->nb);
	printf("list size -> %lld\n", list->size);
	printf("add rear\n");
	node = ft_dcll_addrear(list, 4);
	printf("node address -> %p, value = %d\n", node, node->nb);
	printf("list size -> %lld\n", list->size);

	node = ft_dcll_peekfront(list);
	printf("\ncheck rotation\n");
	for (int i = 0; i <= list->size; i++)
	{
		printf("node address -> %p, value = %d\n", node, node->nb);
		node = node->next;
	}

	node = ft_dcll_peekrear(list);
	printf("check reverse rotation\n");
	for (int i = 0; i <= list->size; i++)
	{
		printf("node address -> %p, value = %d\n", node, node->nb);
		node = node->prev;
	}

	printf("\ncheck pop\n");
	printf("list size -> %lld\n", list->size);
	printf("list front -> %p, list rear -> %p\n", list->front, list->rear);
	printf("pop front\n");
	node = ft_dcll_popfront(list);
	printf("node address -> %p, value = %d\n", node, node->nb);
	free(node);
	printf("list size -> %lld\n", list->size);
	printf("list front -> %p, list rear -> %p\n", list->front, list->rear);
	printf("pop rear\n");
	node = ft_dcll_poprear(list);
	printf("node address -> %p, value = %d\n", node, node->nb);
	free(node);
	printf("list size -> %lld\n", list->size);
	printf("list front -> %p, list rear -> %p\n", list->front, list->rear);
	printf("pop front\n");
	node = ft_dcll_popfront(list);
	printf("node address -> %p, value = %d\n", node, node->nb);
	free(node);
	printf("list size -> %lld\n", list->size);
	printf("list front -> %p, list rear -> %p\n", list->front, list->rear);
	printf("pop rear\n");
	node = ft_dcll_poprear(list);
	printf("node address -> %p, value = %d\n", node, node->nb);
	free(node);
	printf("list size -> %lld\n", list->size);
	printf("list front -> %p, list rear -> %p\n", list->front, list->rear);
	free(list);
}
*/
