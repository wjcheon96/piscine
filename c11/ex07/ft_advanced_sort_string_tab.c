/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:42:32 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/05 10:11:35 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(tab);
	while (i < len)
	{	
		j = 0;
		while (j < len - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
