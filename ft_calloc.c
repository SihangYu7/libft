/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:47:54 by siyu              #+#    #+#             */
/*   Updated: 2024/04/22 16:13:40 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*mem;

	total_size = count * size;
	if (size != 0 && total_size / size != count)
		return (NULL);
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, total_size);
	return (mem);
}
