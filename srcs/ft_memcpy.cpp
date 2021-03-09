/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:25:04 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:32:19 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (char *)dst;
	ptr = (char *)src;
	i = 0;
	while (i != n)
	{
		dest[i] = ptr[i];
		i++;
	}
	return (dest);
}
