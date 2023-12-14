/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:40:42 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/11 17:04:37 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*a;
	size_t			i;

	i = 0;
	a = s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
