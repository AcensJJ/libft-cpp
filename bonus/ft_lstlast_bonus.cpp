/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:00:19 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:25:40 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*beg_lst;

	if (lst == NULL)
		return (NULL);
	beg_lst = lst;
	while (beg_lst->next != NULL)
		beg_lst = beg_lst->next;
	return (beg_lst);
}
