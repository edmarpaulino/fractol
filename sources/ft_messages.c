/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:10:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 11:51:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_message(const char *message)
{
	int		fd;
	char	*line;

	fd = open(message, O_RDONLY);
	while (1)
	{
		if (fd < 0)
			return ;
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		ft_putstr_fd(line, 1);
		free(line);
	}
	close(fd);
}

void	ft_error_message(int error_type)
{
	if (error_type == FEW_ARGS)
		ft_message(ERROR_1);
	else if (error_type == INVALID_ARGS)
		ft_message(ERROR_2);
	ft_message(HELP);
}
