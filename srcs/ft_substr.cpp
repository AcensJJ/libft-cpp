/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:59:20 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:43:08 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (!(ptr = (char *)malloc(len + 1)) || s == 0)
		return (NULL);
	*ptr = 0;
	if (!(start > ft_strlen(s)))
		while (i != len && s[start])
			ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
