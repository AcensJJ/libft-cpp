/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:04:15 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	c = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (c);
}
