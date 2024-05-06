/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:34:02 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 15:30:10 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_c = NULL;

	while (*s)
	{
		if (*s == (char)c)
			last_c = s;
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last_c);
}
