/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:53:48 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 19:01:34 by josesanc         ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_priv_strlen(s));
}
