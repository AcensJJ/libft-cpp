/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:26:09 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

char	*ft_strchr(const char *s, int c)
{
	long		i;
	char		*ptr;

	ptr = (char *)s;
	i = -1;
	if (c == 0)
		return (ptr + ft_strlen(ptr));
	while (ptr[++i] != '\0')
		if (ptr[i] == (char)c)
			return (&ptr[i]);
	return (NULL);
}
