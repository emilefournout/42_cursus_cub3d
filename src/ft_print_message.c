/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:22:21 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/18 17:16:15 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *str)
{
	printf("\033[31;1;4mError\n%s\033[0m\n", str);
}

void	ft_print_warning(char *str)
{
	printf("\033[48:2:255:165:0mWarning: %s\033[0m\n", str);
}
