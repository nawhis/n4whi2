/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:37:05 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:11:56 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list_libft **lst, t_list_libft *new)
{
	if (lst == 0)
		return ;
	if (*lst != 0)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
