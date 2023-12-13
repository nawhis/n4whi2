/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:26 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:13 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list_libft *lst, void (*f)(void *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
