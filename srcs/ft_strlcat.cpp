/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:00:38 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*p_src;

	j = 0;
	i = 0;
	p_src = (char *)src;
	while (i < size)
	{
		if (dst[i] == 0)
			break ;
		if (i == size - 1 && dst[i])
			return (size + ft_strlen(src));
		++i;
	}
	i = ft_strlen(dst);
	while (i + j < size - 1 && p_src[j] && 0 < size)
	{
		dst[i + j] = p_src[j];
		++j;
	}
	dst[i + j] = 0;
	if (size < i)
		return (size + ft_strlen(src));
	return (i + ft_strlen(src));
}
