/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:01:01 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:58:39 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static char	*ft_printf_header(char *original)
{
	char	*new;

	new = ft_strjoin("0x", original);
	free(original);
	return (new);
}

static char	*ft_printf_precision(char *original, t_flags *flags)
{
	char	*padding;
	char	*new;
	int		pad_size;

	pad_size = flags->precision - ft_strlen(original);
	if (ft_strchr(original, '+') || ft_strchr(original, '-'))
		pad_size++;
	if (pad_size <= 0)
		return (original);
	padding = ft_calloc(pad_size + 1, sizeof(char));
	if (!padding)
		return (original);
	ft_memset(padding, '0', pad_size);
	new = ft_strjoin(padding, original);
	free(original);
	free(padding);
	return (new);
}

static char	*ft_printf_width(char *original, t_flags *flags)
{
	char	*padding;
	char	*new;
	int		pad_size;

	pad_size = flags->width - ft_strlen(original);
	if (pad_size <= 0)
		return (original);
	padding = ft_calloc(pad_size + 1, sizeof(char));
	if (!padding)
		return (original);
	if (flags->zero && !flags->minus)
		ft_memset(padding, '0', pad_size);
	else
		ft_memset(padding, ' ', pad_size);
	if (flags->minus)
		new = ft_strjoin(original, padding);
	else
		new = ft_strjoin(padding, original);
	free(original);
	free(padding);
	return (new);
}

void	ft_printf_pointer(unsigned long int n, t_flags *flags, t_list **lst)
{
	char	*number;

	if (!n)
	{
		number = ft_calloc(6, sizeof(char));
		if (!number)
			return ;
		ft_strlcpy(number, "(nil)", 6);
	}
	else
	{
		number = ft_ultoa_base(n, "0123456789abcdef");
		if (flags->precision)
			number = ft_printf_precision(number, flags);
		number = ft_printf_header(number);
	}
	if (flags->width)
		number = ft_printf_width(number, flags);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
