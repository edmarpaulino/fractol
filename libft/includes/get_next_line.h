/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 10:47:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		is_line(char *buffer);
void	att_buffer(char **static_buffer, char **buffer);
char	*get_line(char **static_buffer, char **line);
char	*read_file(int fd, char **buffer);
char	*get_next_line(int fd);

#endif
