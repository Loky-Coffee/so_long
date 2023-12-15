/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:31:51 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/12 02:54:23 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	dstfull;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstfull = dstlen + srclen;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (dstlen < dstsize - 1 && *src)
	{
		dst[dstlen] = *src++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dstfull);
}
