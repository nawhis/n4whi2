/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:19:17 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:10 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list_libft *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = 0;
}
