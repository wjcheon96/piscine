/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:42:06 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/05 10:28:12 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ascend(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_decend(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length -1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_decend(tab, length, f) || ft_ascend(tab, length, f))
		return (1);
	else
		return (0);
}
