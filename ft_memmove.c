/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:04:07 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 15:19:08 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	const char	*last_s;
	char		*last_d;

	d = (char *)dst;
	s = (const char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		last_s = s + (len - 1);
		last_d = d + (len - 1);
		while (len--)
			*last_d-- = *last_s--;
	}
	return (dst);
}
