/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:44 by joushin           #+#    #+#             */
/*   Updated: 2022/05/04 21:23:19 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_atoi_l(char *str, int size)
{
	int	idx;
	int	ret;

	ret = 0;
	idx = 0;
	while (idx < size)
	{
		if ('0' <= str[idx] && str[idx] <= '9')
		{
			ret *= 10;
			ret += str[idx] - '0';
		}
		else
			return (0);
		idx++;
	}
	return (ret);
}

void	update_max(t_data *data, int i, int j)
{
	data->max_n = data->map[i][j];
	data->max_col = j;
	data->max_row = i;
}

void	ft_strcpycat(char *dest, char *src1, char *src2)
{
	while (*src1)
	{
		*dest = *src1;
		dest++;
		src1++;
	}
	while (*src2)
	{
		*dest = *src2;
		dest++;
		src2++;
	}
}

char	*ft_read_files(int fd, t_data *data)
{
	char	*read_str;
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];
	int		size;
	int		len;

	len = 0;
	read_str = (char *)malloc(sizeof(char));
	if (!data->is_valid || read_str == 0)
		return (read_str);
	read_str[0] = 0;
	while (1)
	{
		size = read(fd, buffer, BUFF_SIZE);
		buffer[size] = 0;
		len += size;
		tmp = (char *) malloc(sizeof(char) * (len + 1));
		if (!size || tmp == 0)
			break ;
		tmp[len] = 0;
		ft_strcpycat(tmp, read_str, buffer);
		free(read_str);
		read_str = tmp;
	}
	return (read_str);
}
