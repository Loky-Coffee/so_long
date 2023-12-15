/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:07:39 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/31 14:48:18 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*a;

	i = 0;
	if (s == NULL)
		return (NULL);
	a = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
