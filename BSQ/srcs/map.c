/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:53 by joushin           #+#    #+#             */
/*   Updated: 2022/05/04 21:23:11 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_get_line(char **str, char *buffer, t_data *data)
{
	int	len;

	len = 0;
	if (**str == '\n')
	{
		data->is_valid = 0;
		return (0);
	}
	while (**str)
	{
		if (**str == '\n')
		{
			buffer[len] = 0;
			(*str)++;
			return (len);
		}
		buffer[len] = **str;
		(*str)++;
		len++;
	}
	buffer[len] = 0;
	data->is_valid = 0;
	return (0);
}

void	set_map(t_data *data, char **str)
{
	char	buff[BUFF_SIZE + 1];
	int		idx;
	int		len;

	data->map = (int **) malloc(sizeof(int *) * data->row);
	if (data->map == 0 || !data->is_valid)
	{
		data->is_valid = 0;
		return ;
	}
	len = ft_get_line(str, buff, data);
	is_right_first_line(buff, data, len);
	idx = 1;
	while (idx < data->row)
	{
		len = ft_get_line(str, buff, data);
		init_line(buff, data, idx, len);
		idx++;
	}
	if (**str != 0)
		data->is_valid = 0;
}

void	print_map(t_data *data)
{
	int		i;
	int		j;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == 0)
				buff[j] = data->obstacle;
			else if ((data->max_row - data->max_n) < i
				&& i <= data->max_row
				&& (data->max_col - data->max_n) < j
				&& j <= data->max_col)
				buff[j] = data->filled;
			else
				buff[j] = data->empty;
			j++;
		}
		write(1, buff, data->col);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_get_min(int x, int y, int z)
{
	int	min;

	min = x;
	if (min > y)
		min = y;
	if (min > z)
		min = z;
	return (min + 1);
}

void	sol_map(t_data *data)
{
	int	i;
	int	j;

	if (!data->is_valid)
		return ;
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] != 0)
			{
				if (i != 0 && j != 0)
					data->map[i][j] = ft_get_min(data->map[i - 1][j - 1],
							data->map[i][j - 1], data->map[i - 1][j]);
				if (data->map[i][j] > data->max_n)
					update_max(data, i, j);
			}
			j++;
		}
		i++;
	}
}
