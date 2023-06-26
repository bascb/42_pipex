/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:40:18 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:57:59 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_str
{
	size_t			size;
	char			*str;
}					t_str;

static size_t	ft_printf_buffer_size(t_list **lst)
{
	size_t	size;
	t_list	*next;
	t_str	*n;

	size = 0;
	next = *lst;
	while (next)
	{
		n = (t_str *) next->content;
		size += n->size;
		next = next->next;
	}
	return (size);
}

void	ft_del(void *data)
{
	t_str	*d;

	d = (t_str *) data;
	free(d->str);
	free(d);
}

size_t	ft_strncat(char *dest, t_str *content, size_t buffer_size, size_t i)
{
	size_t	j;

	j = 0;
	while (j < content->size && i < buffer_size)
	{
		dest[i] = content->str[j];
		i++;
		j++;
	}
	return (i);
}

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size)
{
	t_str	*str_data;

	str_data = ft_calloc(1, sizeof(t_str));
	if (!str_data)
		return ;
	str_data->str = ft_calloc(size + 1, sizeof(char));
	if (!str_data->str)
	{
		free(str_data);
		return ;
	}
	str_data->size = size;
	ft_memcpy(str_data->str, str, size);
	ft_lstadd_back(lst, ft_lstnew(str_data));
}

int	ft_printf_buffer_output(t_list **lst)
{
	size_t	buff_size;
	size_t	i;
	char	*buffer;
	t_list	*next;

	buff_size = ft_printf_buffer_size(lst);
	buffer = ft_calloc(buff_size + 1, sizeof(char));
	if (!buffer)
	{
		ft_lstclear(lst, ft_del);
		free(lst);
		return (-1);
	}
	next = *lst;
	i = 0;
	while (next)
	{
		i = ft_strncat(buffer, next->content, buff_size, i);
		next = next->next;
	}
	write(1, buffer, buff_size);
	ft_lstclear(lst, ft_del);
	free(buffer);
	free(lst);
	return ((int) buff_size);
}
