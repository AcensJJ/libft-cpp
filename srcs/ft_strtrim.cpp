/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:00:05 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:43:17 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

static int		ft_is_set(char const *s1, char const *set, size_t i)
{
	size_t	j;

	j = 0;
	while (set[j] && set[j] != s1[i])
		j++;
	if (s1[i] == set[j])
		return (1);
	return (0);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_is_set(s1, set, i) == 1)
		i++;
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i != 0 && ft_is_set(s1, set, i) == 1)
		i--;
	i++;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*ptr;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	if (ft_start(s1, set) < ft_end(s1, set))
	{
		if (!(ptr = (char *)malloc(ft_end(s1, set) - ft_start(s1, set) + 1)))
			return (NULL);
		*ptr = 0;
		while (i + ft_start(s1, set) != ft_end(s1, set))
		{
			ptr[i] = s1[i + ft_start(s1, set)];
			i++;
		}
	}
	else
		return ((char *)ft_calloc(1, 1));
	ptr[i] = 0;
	return (ptr);
}
