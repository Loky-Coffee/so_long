/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:18:05 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/16 16:57:42 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	while ((*haystack && len >= i) || (i == 0))
	{
		if ((ft_strncmp(haystack, needle, i) == 0) || (i == 0))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
