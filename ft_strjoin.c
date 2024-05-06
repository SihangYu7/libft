/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:25:32 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 15:21:24 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	l_total;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l_total = l1 + l2;
	str = (char *)malloc(sizeof(char) * (l_total + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l_total] = '\0';
	return (str);
}
