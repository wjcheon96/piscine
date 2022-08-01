/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:56:01 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/26 18:53:38 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (_ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
