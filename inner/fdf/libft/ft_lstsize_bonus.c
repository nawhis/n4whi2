/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:10:46 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:32 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list_libft *lst)
{
	int	length;

	length = 0;
	while (lst != 0)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}
