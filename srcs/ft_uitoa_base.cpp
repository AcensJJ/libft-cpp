/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:29:53 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:41:30 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

static void		ft_config_ptr2(unsigned long nb, char *ptr, char *base,
								long count)
{
	long				reste;
	long				j;
	unsigned long long	len;
	long				c;
	int					i;

	i = ft_strlen(base);
	c = count;
	len = i;
	c == 1 ? len /= i : 0;
	while (c-- - 1 > 1)
		len *= i;
	j = -1;
	if (count == 0)
		ptr[++j] = base[0];
	while (count > 0)
	{
		reste = nb % len;
		ptr[++j] = base[((nb - reste) / len)];
		len /= i;
		nb = reste;
		count--;
	}
	ptr[++j] = 0;
}

static int		ft_ucount_nbr_base(unsigned long n, unsigned long len)
{
	unsigned long long	i;
	long				count;

	count = 0;
	i = n;
	while (i)
	{
		i /= len;
		count++;
	}
	return (count);
}

char			*ft_uitoa_base(void *n, char *base)
{
	char				*ptr;
	unsigned long		nb;
	unsigned long		i;
	long				count;

	nb = (unsigned long)n;
	i = ft_strlen(base);
	count = ft_ucount_nbr_base(nb, i);
	if (!(ptr = (char *)malloc(count + 1)))
		return (NULL);
	*ptr = 0;
	ft_config_ptr2(nb, ptr, base, count);
	return (ptr);
}
