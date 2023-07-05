/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:54:54 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/08 16:23:50 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_string
{
	char	*str;
	ssize_t	size;
}	t_string;

char		*get_next_line(int fd);
int			gnl_shorten(t_string *fd_set[], ssize_t upto, int fd);
int			gnl_buff(t_string *res, t_string *fd_set[], int fd);
char		*gnl_return_and_free(t_string	*string);
char		*gnl_stjon(char *s1, char *s2, ssize_t size_x, ssize_t size_y);
ssize_t		gnl_bytestojoin(char *s1, ssize_t end);
char		*gnl_readloop(t_string *res, t_string *fd_set[], int fd);
int			gnl_aux(t_string *fd_set[], int fd);
char		*gnl_free_buff_and_return(t_string *res,
				t_string *fd_set[], int fd);
char		*gnl_null_exit(t_string *res, t_string *fd_set[], int fd);

#endif