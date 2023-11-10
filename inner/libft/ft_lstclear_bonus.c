/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:29:29 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/16 14:35:47 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev_node;
	t_list	*curr_node;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	curr_node = *lst;
	while (curr_node)
	{
		prev_node = curr_node;
		curr_node = curr_node->next;
		ft_lstdelone(prev_node, del);
	}
	*lst = 0;
}
