/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:04:08 by siyu              #+#    #+#             */
/*   Updated: 2024/04/29 14:06:47 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	if (n / 10 == 0)
	{
		if (n < 0)
			return (2);
		else
			return (1);
	}
	return (1 + get_len(n / 10));
}

static void	convert(int n, char *a_str, size_t len_int)
{
	long	long_n;
	size_t	start_index;

	long_n = n;
	start_index = 0;
	if (long_n < 0)
	{
		*a_str = '-';
		long_n = -long_n;
		start_index++;
	}
	while (len_int-- > start_index)
	{
		a_str[len_int] = long_n % 10 + '0';
		long_n = long_n / 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len_int;
	char	*a_str;

	len_int = get_len(n);
	a_str = (char *)malloc(sizeof(*a_str) * (len_int + 1));
	if (!a_str)
		return (NULL);
	convert(n, a_str, len_int);
	a_str[len_int] = 0;
	return (a_str);
}
