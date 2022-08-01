/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:11:13 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/18 10:25:01 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	num;

	num = 0;
	temp = 0;
	while (num < (size / 2))
	{
		temp = tab[size - (1 + num)];
		tab[size - (1 + num)] = tab[num];
		tab[num] = temp;
		num++;
	}
}
