/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:08:28 by joushin           #+#    #+#             */
/*   Updated: 2022/05/04 21:23:00 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	free_all(t_data *data, char *str)
{
	int	idx;

	idx = 0;
	while (idx < data->row)
	{
		free(data->map[idx]);
		idx++;
	}
	free(data->map);
	free(str);
}

void	bsq_solve(int fd, t_data *data)
{
	char	*str;
	char	*tmp;

	data->is_valid = 1;
	if (fd < 0)
		data->is_valid = 0;
	str = ft_read_files(fd, data);
	tmp = str;
	init_first_data(data, &str);
	if (!is_valid_data(data))
		data->is_valid = 0;
	set_map(data, &str);
	sol_map(data);
	if (fd != 0)
		close(fd);
	if (data->is_valid)
		print_map(data);
	else
		write(2, "map error\n", 10);
	free_all(data, tmp);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		idx;
	t_data	data;

	idx = 1;
	if (argc <= 1)
	{
		fd = 0;
		bsq_solve(fd, &data);
	}
	else
	{
		while (idx < argc)
		{
			fd = open(argv[idx], O_RDONLY);
			bsq_solve(fd, &data);
			if (idx < argc - 1)
				write(1, "\n", 1);
			idx++;
		}
	}
	return (0);
}
