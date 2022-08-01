/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:37:34 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/05 10:25:37 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (length + 1));
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}
