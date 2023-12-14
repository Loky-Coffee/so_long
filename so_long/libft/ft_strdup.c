/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:56:32 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/18 04:12:25 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (*s1 != '\0')
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}
