/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:57:00 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:26:48 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

t_list		*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (s_list *)malloc(sizeof(t_list))))
		return (0);
	(*list).content = content;
	list->next = NULL;
	return (list);
}
