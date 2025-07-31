/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:25:48 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/24 12:46:56 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_content;
	t_list	*new_elem;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_lst = NULL;
	while (temp)
	{
		new_content = f(temp->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			del(new_content);
			ft_lstclear(&new_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		temp = temp->next;
	}
	return (new_lst);
}
