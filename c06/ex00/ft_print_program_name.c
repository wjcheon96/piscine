/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:11:37 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/27 11:10:01 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	len;

	len = ft_strlen(argv[0]);
	if (argc >= 1)
	{
		write(1, argv[0], len);
		write(1, "\n", 1);
	}
	return (0);
}
