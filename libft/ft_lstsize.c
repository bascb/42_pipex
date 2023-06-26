/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:43 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/01 18:16:47 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in list */
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*next;

	count = 0;
	next = lst;
	while (next)
	{
		count++;
		next = next->next;
	}
	return (count);
}
