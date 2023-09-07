/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:46:34 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/07 16:06:14 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (!lst || !f)
		return ;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
/*Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément*/
