/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:11:50 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:25:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *beg_lst;
	t_list *temp;

	if (lst == NULL || del == NULL)
		return ;
	beg_lst = *lst;
	while (beg_lst)
	{
		temp = beg_lst->next;
		ft_lstdelone(beg_lst, del);
		beg_lst = temp;
	}
	*lst = NULL;
}
