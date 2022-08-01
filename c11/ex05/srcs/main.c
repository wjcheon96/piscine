/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:31 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/05 10:11:01 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_operator(char *str)
{
	if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '*')
		return (2);
	else if (*str == '/')
		return (3);
	else if (*str == '%')
		return (4);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		idx;
	void	(*func[5])(int, int);

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (ft_strlen(argv[2]) != 1 || ft_operator(argv[2]) == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	idx = ft_operator(argv[2]);
	func[0] = ft_plus;
	func[1] = ft_minus;
	func[2] = ft_multiple;
	func[3] = ft_division;
	func[4] = ft_mod;
	func[idx](a, b);
	return (0);
}
