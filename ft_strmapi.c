/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:13:07 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 15:23:18 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rslt;
	char	*modified_str;

	if (!s)
		return (NULL);
	modified_str = (char *)malloc(sizeof(*modified_str) * (ft_strlen(s) + 1));
	if (!modified_str)
		return (NULL);
	rslt = modified_str;
	i = 0;
	while (s[i])
	{
		modified_str[i] = f(i, s[i]);
		i++;
	}
	modified_str[i] = '\0';
	return (rslt);
}
