/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:09:29 by joushin           #+#    #+#             */
/*   Updated: 2022/05/04 21:21:56 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 4000000

typedef struct s_data
{
	int		**map;
	int		row;
	int		col;
	int		max_row;
	int		max_col;
	int		max_n;
	int		is_valid;
	char	empty;
	char	obstacle;
	char	filled;

}	t_data;

//tool.c 
int		ft_atoi_l(char *str, int size);
char	*ft_read_files(int fd, t_data *data);
void	update_max(t_data *data, int i, int j);
void	ft_strcpycat(char *dest, char *src1, char *src2);

//check.c
int		is_valid_data(t_data *data);
int		is_right_first_line(char *str, t_data *data, int len);
int		init_line(char *str, t_data *data, int row, int len);
void	init_first_data(t_data *data, char **str);

//map.c
int		ft_get_line(char **str, char *buff, t_data *data);
int		ft_get_min(int x, int y, int z);
void	set_map(t_data *data, char **str);
void	print_map(t_data *data);
void	sol_map(t_data *data);

//main.c 
void	bsq_solve(int fd, t_data *data);
void	free_all(t_data *data, char *str);

#endif
