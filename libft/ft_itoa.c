/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:56:18 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:15:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a string representing the
*	integer received as an argument. Negative numbers must be handled.
*
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static char	*ft_convert(int n, char *str)
{
	int	len;

	if (n < 0)
	{
		n *= -1;
		len = (ft_intlen(n) + 2);
		str = (char *)malloc(len * sizeof(*str));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		len = (ft_intlen(n) + 1);
		str = (char *)malloc(len * sizeof(*str));
		if (!str)
			return (NULL);
	}
	str[--len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = 0;
	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else if (n == 0)
		str = ft_strdup("0");
	else
		str = ft_convert(n, str);
	return (str);
}
