/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:20:07 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 18:09:47 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_is_space(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

static int	sign_check(char c, int sign)
{
	if (c == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			rslt;
	long			check;

	i = 0;
	while (if_is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = sign_check(str[i], sign);
		i++;
	}
	rslt = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = rslt * 10 + (str[i++] - '0');
		if (check / 10 != rslt && sign == 1)
			return (-1);
		if (check / 10 != rslt && sign == -1)
			return (0);
		rslt = check;
	}
	return (rslt * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    char    s[50] = "2022000000000000000000000";
    int        a;
    int        ft;

    printf("str is: %s\n", s);
    a = atoi(s);
    printf("atoi: %d\n", a);
    ft = ft_atoi(s);
    printf("ft: %d\n", ft);
    return (0);
}*/
