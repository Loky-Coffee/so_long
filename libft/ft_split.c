/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:04:15 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/15 15:23:07 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wortcounter(char const *s, char c)
{
	int	i;
	int	strcounter;

	i = 0;
	strcounter = 0;
	if (!s || s[0] == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			strcounter++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		strcounter++;
	if (s[0] == '\0')
		strcounter = 0;
	return (strcounter);
}

static int	mallocfree(char	**newarray, int i)
{
	while (i > 0)
	{
		free(newarray[i - 1]);
		i--;
	}
	free (newarray);
	return (0);
}

static int	stringmake(int wortcount, char const *s, char c, char	**newarray)
{
	int	i;
	int	a;
	int	j;
	int	charcount;

	i = 0;
	j = 0;
	while (i < wortcount)
	{
		charcount = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j + charcount] != c && s[j + charcount] != '\0')
			charcount++;
		newarray[i] = (char *)ft_calloc(charcount + 1, (sizeof(char)));
		if (newarray[i] == NULL)
			return (mallocfree(newarray, i));
		a = 0;
		while (charcount > a && s[j])
			newarray[i][a++] = s[j++];
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wortcount;
	char	**newarray;

	if (s == NULL)
		return (NULL);
	wortcount = wortcounter(s, c);
	newarray = (char **)ft_calloc(wortcount + 1, sizeof(char *));
	if (!newarray)
		return (NULL);
	if (stringmake(wortcount, s, c, newarray) == 0)
	{
		free(newarray);
		return (NULL);
	}
	return (newarray);
}
