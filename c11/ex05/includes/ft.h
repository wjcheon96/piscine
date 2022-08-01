/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:58:58 by wcheon            #+#    #+#             */
/*   Updated: 2022/05/03 17:35:56 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_plus(int a, int b);
void	ft_minus(int a, int b);
void	ft_multiple(int a, int b);
void	ft_division(int a, int b);
void	ft_mod(int a, int b);
int		ft_operator(char *str);
int		ft_strlen(char *str);

#endif
