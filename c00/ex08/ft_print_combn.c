/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:46:59 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/17 15:04:43 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<unistd.h>

void	dfs(int index, int num, int n, char *memory)
{
	if (index == n)
	{
		write(1, memory, n);
		if (memory[0] != 10 - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (num <= 9)
		{
			memory[index] = num + '0';
			dfs(index + 1, num + 1, n, memory);
			num++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	memory[10];

	dfs(0, 0, n, memory);
}

#include <stdio.h>

int main()
{
	int nb;
	scanf ("%d", &nb);
	ft_print_combn(nb);
}