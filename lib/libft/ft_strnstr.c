/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:29:26 by josesanc          #+#    #+#             */
/*   Updated: 2022/12/03 18:45:28 by josesanc         ###   ########.fr       */
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

static const char	*startchar(const char *str, const char *to_find)
{
	int	counter;

	counter = 0;
	while (str[counter] == to_find[counter])
	{
		counter++;
		if (str[counter] == '\0' && to_find[counter] == '\0')
			return (str);
	}
	if (to_find[counter] == '\0')
		return (str);
	else
		return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		counter;
	size_t		needle_len;
	const char	*res;

	counter = 0;
	needle_len = ft_priv_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	res = startchar(&haystack[counter], &needle[0]);
	if (counter + needle_len > len)
		return (NULL);
	while (res == NULL && haystack[counter] != '\0'
		&& counter + needle_len < len)
	{
		counter++;
		res = startchar(&haystack[counter], &needle[0]);
	}
	return ((char *)res);
}
