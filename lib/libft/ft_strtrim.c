/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:03:50 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:58:02 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_priv_strlen(const char *s)
{
	int	cont;

	cont = 0;
	while (s[cont] != 0)
		cont++;
	return (cont);
}

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (1);
	while (set[i] != 0)
		if (set[i++] == c)
			return (1);
	return (0);
}

static char	*ft_error_case(void)
{
	char	*res;

	res = (char *) malloc (1);
	if (res != NULL)
		res[0] = 0;
	return (res);
}

static void	ft_setp(char const *s1, char const *set, size_t *start, size_t *end)
{
	size_t	size;

	size = ft_priv_strlen(s1);
	*start = 0;
	*end = size - 1;
	while (s1[*start] != 0 && ft_isinset(s1[*start], set))
		(*start)++;
	while ((*end) >= 0 && ft_isinset(s1[*end], set))
	{
		if (*end == 0)
			return ;
		(*end)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == NULL || *s1 == 0)
		return (ft_error_case());
	ft_setp(s1, set, &start, &end);
	if (start > end)
		return (ft_error_case());
	res = (char *) malloc (end - start + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
