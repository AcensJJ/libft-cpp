/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:16:12 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:41:35 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

static void		ft_config_ptr(unsigned long long nb, unsigned long long i,
							long long j, char *ptr)
{
	long long	reste;

	while (nb >= i)
		i *= 10;
	while (i >= 10)
	{
		i /= 10;
		reste = nb % i;
		ptr[++j] = ((nb - reste) / i) + 48;
		nb = reste;
	}
	ptr[++j] = 0;
}

static int		ft_ucount_nbr(unsigned long long n)
{
	unsigned long long	i;
	long long			count;

	count = 1;
	i = 10;
	while (n >= i)
	{
		i *= 10;
		count++;
	}
	return (count);
}

char			*ft_uitoa(unsigned int n)
{
	char					*ptr;
	unsigned long long		nb;
	unsigned long long		i;
	long long				j;

	nb = (unsigned long long)n;
	j = -1;
	if (!(ptr = (char *)malloc(ft_ucount_nbr(nb) + 1)))
		return (NULL);
	*ptr = 0;
	i = 10;
	ft_config_ptr(nb, i, j, ptr);
	return (ptr);
}
