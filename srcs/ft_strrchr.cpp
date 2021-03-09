/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:32:56 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	last = 0;
	if (c == 0)
		return (ptr + ft_strlen(ptr));
	while (i != ft_strlen(ptr))
	{
		if (ptr[i] == (char)c)
			last = i;
		i++;
	}
	if (ptr[last] == (char)c)
		return (&ptr[last]);
	return (NULL);
}
