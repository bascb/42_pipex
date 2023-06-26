/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:44 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:58:19 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static void	ft_printf_width(char c, t_flags *flags, t_list **lst)
{
	char	*padding;

	padding = ft_calloc(flags->width + 1, sizeof(char));
	if (!padding)
	{
		ft_printf_buffer_add(lst, &c, 1);
		return ;
	}
	ft_memset(padding, ' ', flags->width);
	if (flags->minus)
		padding[0] = c;
	else
		padding[flags->width - 1] = c;
	ft_printf_buffer_add(lst, padding, flags->width);
	free(padding);
}

void	ft_printf_chr(char c, t_flags *flags, t_list **lst)
{		
	if (flags->width > 1)
		ft_printf_width(c, flags, lst);
	else
		ft_printf_buffer_add(lst, &c, 1);
}
