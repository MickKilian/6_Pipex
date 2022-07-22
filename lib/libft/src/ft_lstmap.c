/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 03:59:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/07 02:28:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*elem;

	newlst = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem)
			ft_lstadd_back(&newlst, elem);
		else
		{
			ft_lstclear(&newlst, del);
			break ;
		}
		lst = lst->next;
	}
	return (newlst);
}
