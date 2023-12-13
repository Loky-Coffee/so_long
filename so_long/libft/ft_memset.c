/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:47:50 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/09 13:33:49 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	int				i;

	a = b;
	i = 0;
	while (len >= 1)
	{
		a[i] = c;
		i++;
		len--;
	}
	return (b);
}
