/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:45:12 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*ptr;

	dest = (unsigned char *)dst;
	ptr = (unsigned char *)src;
	i = 0;
	while (i != n)
	{
		dest[i] = ptr[i];
		if (ptr[i] == (unsigned char)c)
			return (&dest[++i]);
		i++;
	}
	return (NULL);
}
