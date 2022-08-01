/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:58:39 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 23:50:01 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_ft_strlen(char *strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	*ft_strcat(char *arr, char *strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
		i++;
	while (strs[j])
	{
		arr[i + j] = strs[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*arr;
	int		i;

	len = 0;
	i = -1;
	if (size == 0)
	{
		arr = (char *)malloc(1);
		arr[0] = '\0';
		return (arr);
	}
	while (++i < size)
		len += _ft_strlen(strs[i]);
	len = (size - 1) * _ft_strlen(sep) + len;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	arr[0] = '\0';
	while (++i < size - 1)
	{
		arr = ft_strcat(arr, strs[i]);
		arr = ft_strcat(arr, sep);
	}
	arr = ft_strcat(arr, strs[i]);
	return (arr);
}
/*

#include <stdio.h>

int main()
{
	printf("-------ex03-------\n\n");
    char *ex03_arr1;
    char *ex03_arr2;
    char *ex03_arr3;
	char *ex03_str[5];

	ex03_str[0] = "hello";
	ex03_str[1] = "my";
	ex03_str[2] = "name";
	ex03_str[3] = "is";
	ex03_str[4] = "hunpark!";
	ex03_arr1 = ft_strjoin(5, ex03_str, " ");
    ex03_arr2 = ft_strjoin(5, ex03_str, ".");
    ex03_arr3 = ft_strjoin(5, ex03_str, "-");
	printf("%s\n", ex03_arr1);
    printf("%s\n", ex03_arr2);
    printf("%s\n\n", ex03_arr3);
    free(ex03_arr1);
    free(ex03_arr2);
    free(ex03_arr3);
}*/
