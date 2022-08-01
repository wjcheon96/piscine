/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:14:27 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 23:49:35 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	__ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = __ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
	printf("\n----------------------ex00----------------------------\n");
	char arr[10] = "abcdef";
	char *src;
	src = ft_strdup(arr);
	printf("%s",src);
}
*/
