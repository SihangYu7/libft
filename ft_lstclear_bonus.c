/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:19:25 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 18:12:32 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;

	if (!(*lst) || !lst || !del)
		return ;
	while (*lst)
	{
		temp_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp_lst, del);
	}
}
