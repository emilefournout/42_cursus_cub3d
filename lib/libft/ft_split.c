/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:59:53 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/30 12:35:07 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	if (str[0] == 0)
		return (0);
	while (str[i] != 0 && str[i] == c)
		i++;
	while (str[i] != 0)
	{
		while (str[i] != 0 && str[i] != c)
			i++;
		words++;
		while (str[i] != 0 && str[i] == c)
			i++;
	}
	return (words);
}

static int	ft_strdup_until(char **res, int word, const char *src, char c)
{
	int		i;
	int		len;

	i = 0;
	while (src[i] != 0 && src[i] != c)
		i++;
	len = i;
	res[word] = (char *)malloc(len + 1);
	if (res[word] == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		res[word][i] = src[i];
		i++;
	}
	res[word][i] = 0;
	return (0);
}

static int	ft_omit_c(char *str, char c, int index)
{
	while (str[index] != 0 && str[index] == c)
		index++;
	return (index);
}

static void	*ft_freesplit(char ***res, int words)
{
	while (words >= 0)
	{
		free((*res)[words]);
		words--;
	}
	free(*res);
	*res = NULL;
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		words;
	int		w;
	int		ci;

	w = 0;
	ci = 0;
	words = ft_countwords((char *)str, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (res);
	while (w < words)
	{
		ci = ft_omit_c((char *)str, c, ci);
		if (ft_strdup_until(res, w, &(str[ci]), c) == -1)
			return (ft_freesplit(&res, w - 1));
		while (str[ci] != 0 && str[ci] != c)
			ci++;
		w++;
	}
	res[w] = NULL;
	return (res);
}
