/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:16:49 by aalatzas          #+#    #+#             */
/*   Updated: 2023/12/19 02:23:05 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Frees the allocated memory for each string in the array and the array itself.
/// This function iterates through an array of strings, freeing each string, and then
/// frees the array itself. It is safe to call with a NULL pointer, in which case
/// the function does nothing.
/// @param split_array An array of strings, each dynamically allocated, followed by a NULL terminator.
void	free_split(char **split_array)
{
	int	i;

	i = 0;
	if (split_array == NULL)
		return ;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
