/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:05:31 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 20:34:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_merge(int *arr, int start, int mid, int end)
{
	int	*tmp;
	int	i;
	int	j;
	int	k;

	tmp = (int *)malloc(sizeof(int) * (end - start + 1));
	if (tmp == NULL)
		return ;
	i = start;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];
	ft_memcpy(&arr[start], tmp, sizeof(int) * (end - start + 1));
	free(tmp);
}

void	ft_merge_sort(int *arr, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		ft_merge_sort(arr, start, mid);
		ft_merge_sort(arr, mid + 1, end);
		ft_merge(arr, start, mid, end);
	}
}
