/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:44:45 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/12 17:41:17 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstsize = dstsize -1;
	if (dstsize != 0)
	{
		while (dstsize != 0 && *src != '\0')
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = '\0';
		return (srclen);
	}
	*dst = '\0';
	return (srclen);
}
