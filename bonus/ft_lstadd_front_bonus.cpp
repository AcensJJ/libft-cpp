/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:49:38 by jacens            #+#    #+#             */
/*   Updated: 2021/03/16 17:26:24 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	ft_lstadd_front(t_list **alst, t_list *news)
{
	if (alst == NULL || news == NULL)
		return ;
	news->next = *alst;
	*alst = news;
}
