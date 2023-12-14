/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:35:36 by aalatzas          #+#    #+#             */
/*   Updated: 2023/11/18 01:01:36 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	maxlen;

	maxlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = ft_calloc(maxlen, 1);
	if (!newstr)
		return (NULL);
	ft_strlcat(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, maxlen);
	return (newstr);
}
