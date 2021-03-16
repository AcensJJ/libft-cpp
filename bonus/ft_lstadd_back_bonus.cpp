/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:26:52 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:26:18 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	ft_lstadd_back(t_list **alst, t_list *news)
{
	t_list *beg_lst;

	if (alst == NULL || news == NULL)
		return ;
	if (*alst == NULL)
		*alst = news;
	else
	{
		beg_lst = ft_lstlast(*alst);
		beg_lst->next = news;
	}
}
