/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:45:56 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/13 15:09:48 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	stringlen1;

	stringlen1 = (ft_strlen(s));
	if (stringlen1 <= start)
		len = 0;
	else if ((stringlen1 - start) < len)
		len = stringlen1 - start;
	newstr = (char *)ft_calloc(len + 1, 1);
	if (newstr == NULL)
		return (NULL);
	if (len > 0 && s[start])
		ft_strlcpy(newstr, &s[start], len + 1);
	return (newstr);
}
