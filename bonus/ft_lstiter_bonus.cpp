/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:50:09 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:25:34 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*beg_lst;

	if (lst == NULL || f == NULL)
		return ;
	beg_lst = lst;
	while (beg_lst != NULL)
	{
		f(beg_lst->content);
		beg_lst = beg_lst->next;
	}
}
