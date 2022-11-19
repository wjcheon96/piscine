/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:36 by joushin           #+#    #+#             */
/*   Updated: 2022/05/04 21:22:50 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	is_valid_data(t_data *data)
{
	if (data->is_valid == 0)
		return (0);
	if (data->row == 0)
		return (0);
	if (data->obstacle == data->filled || data->obstacle == data->empty
		|| data->filled == data->empty)
		return (0);
	return (1);
}

int	is_right_first_line(char *str, t_data *data, int len)
{
	int	idx;

	data->col = len;
	data->map[0] = (int *)malloc(sizeof(int) * data->col);
	if (data->map[0] == 0)
	{
		data->is_valid = 0;
		return (0);
	}
	idx = 0;
	while (idx < data->col)
	{
		if (str[idx] == data->obstacle)
			data->map[0][idx] = 0;
		else if (str[idx] == data->empty)
			data->map[0][idx] = 1;
		else
		{
			data->is_valid = 0;
			return (0);
		}
		idx++;
	}
	return (1);
}

int	init_line(char *str, t_data *data, int row, int len)
{
	int	idx;

	data->map[row] = (int *)malloc(sizeof(int) * data->col);
	if (data->col != len || data->map[row] == 0)
	{
		data->is_valid = 0;
		return (0);
	}
	idx = 0;
	while (idx < data->col)
	{
		if (str[idx] == data->obstacle)
			data->map[row][idx] = 0;
		else if (str[idx] == data->empty)
			data->map[row][idx] = 1;
		else
		{
			data->is_valid = 0;
			return (0);
		}
		idx++;
	}
	return (1);
}

void	init_first_data(t_data *data, char **str)
{
	char	buff[BUFF_SIZE + 1];
	int		len;

	data->row = 0;
	data->col = 0;
	if (!data->is_valid)
		return ;
	len = ft_get_line(str, buff, data);
	if (buff[0] == 0)
		data->is_valid = 0;
	data->max_n = 0;
	if (len < 4)
		data->is_valid = 0;
	else
	{
		data->filled = buff[len - 1];
		data->obstacle = buff[len - 2];
		data->empty = buff[len - 3];
		data->row = ft_atoi_l(buff, len - 3);
	}
	data->max_row = -1;
	data->max_col = -1;
}
