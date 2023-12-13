/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:12:51 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:17 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstlast(t_list_libft *lst)
{
	if (lst != 0)
	{
		while (lst->next != 0)
			lst = lst->next;
	}
	return (lst);
}
