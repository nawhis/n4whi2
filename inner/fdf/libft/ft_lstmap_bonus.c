/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:53:12 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:22 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_libft	*new_lst;
	t_list_libft	*node;
	void	*ptr;

	new_lst = 0;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst != 0)
	{
		ptr = (*f)(lst->content);
		node = ft_lstnew(ptr);
		if (!node || !ptr)
		{
			del(ptr);
			free(node);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
