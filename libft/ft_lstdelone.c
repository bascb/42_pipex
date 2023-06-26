/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:11:31 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/01 22:11:34 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Removes a node from list */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst)
		return ;
	aux = lst;
	if (del != NULL)
		del(lst->content);
	lst = lst->next;
	free(aux);
}
