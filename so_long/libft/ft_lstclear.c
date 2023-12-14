/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:27:28 by aalatzas          #+#    #+#             */
/*   Updated: 2023/10/19 04:22:34 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hier;
	t_list	*next;

	hier = *lst;
	while (hier != NULL)
	{
		next = hier->next;
		del(hier->content);
		free(hier);
		hier = next;
	}
	*lst = NULL;
}
