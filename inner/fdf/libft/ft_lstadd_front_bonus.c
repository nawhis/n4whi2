/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:59:32 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:01 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list_libft **lst, t_list_libft *new)
{
	t_list_libft	*prev_head;

	if (lst == 0)
		return ;
	prev_head = *lst;
	*lst = new;
	new = ft_lstlast(new);
	new->next = prev_head;
}
