/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:56:16 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:12:37 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*new_node;

	new_node = (t_list_libft *)malloc(sizeof(t_list_libft));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
