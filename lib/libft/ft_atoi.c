/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:29 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/01 19:19:24 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_priv_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		negative;
	size_t	cont;

	res = 0;
	negative = 0;
	cont = 0;
	while (ft_isspace(str[cont]))
		cont++;
	if (str[cont] == '+' || str[cont] == '-')
		if (str[cont++] == '-')
			negative = 1;
	while (ft_priv_isdigit(str[cont]))
	{
		if (negative)
			res = (res * 10) - (str[cont] - '0');
		else
			res = (res * 10) + (str[cont] - '0');
		cont++;
	}
	return (res);
}
