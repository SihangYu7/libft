/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:41:27 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 15:21:38 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	max_cpy_len;
	size_t	i;	

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	if (dst_len == dstsize)
		return (dst_len + src_len);
	max_cpy_len = dstsize - dst_len - 1;
	while (i < max_cpy_len && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
