/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:17:37 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:17:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Outputs the character ’c’ to the given file descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
