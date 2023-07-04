/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:33:16 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/07 15:33:09 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp_next;
	}
	*lst = NULL;
}
