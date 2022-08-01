/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcheon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:33:04 by wcheon            #+#    #+#             */
/*   Updated: 2022/04/30 15:49:08 by wcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_is_sep(str[i], charset))
			i++;
	}
	return (count);
}

char	*put_word(char *str, char *charset)
{
	int		i;
	char	*word;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && !ft_is_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == 0)
		return (0);
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**arr;
	int		count;

	i = 0;
	count = word_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (0);
	while (*str)
	{
		while (ft_is_sep(*str, charset) && *str)
			str++;
		if (*str)
		{
			arr[i] = put_word(str, charset);
			i++;
		}
		while (!ft_is_sep(*str, charset) && *str)
			str++;
	}
	arr[i] = 0;
	return (arr);
}

#include <stdio.h>

int main()
{
	printf("\n----------------------ex05----------------------------\n");
	char str[1000] ="          hi my name is joushin I don't know this problem";
	char sep[100] = " ";
	char **result = ft_split(str, sep);
	for (int i = 0; result[i] != 0; i++)
	printf("%d :::::%s\n\n",i,result[i]);
}

