/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:44 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:58:33 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

static void	ft_forward_sign(char *number)
{
	char	*sign;

	if (number[0] == '0')
	{
		sign = number;
		while (*sign && *sign != '+' && *sign != '-')
			sign++;
		if (*sign == '+' || *sign == '-')
		{
			number[0] = *sign;
			*sign = '0';
		}	
	}
}

static char	*ft_printf_signal_flag(char *original, char c)
{
	char	*new;

	if (c == '+')
		new = ft_strjoin("+", original);
	else
		new = ft_strjoin(" ", original);
	free(original);
	return (new);
}

static char	*ft_printf_precision(int n, char *original, t_flags *flags)
{
	char	*padding;
	char	*new;
	int		pad_size;

	if (!n && !flags->precision)
	{
		new = ft_strdup("");
		free(original);
		return (new);
	}
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
	ft_forward_sign(new);
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
	if (flags->zero && !flags->minus && !flags->precision)
		ft_memset(padding, '0', pad_size);
	else
		ft_memset(padding, ' ', pad_size);
	if (flags->precision_flag && !flags->precision)
		ft_memset(padding, ' ', pad_size);
	if (flags->minus)
		new = ft_strjoin(original, padding);
	else
		new = ft_strjoin(padding, original);
	free(original);
	free(padding);
	ft_forward_sign(new);
	return (new);
}

void	ft_printf_int(int n, t_flags *flags, t_list **lst)
{
	char	*number;

	number = ft_itoa(n);
	if (flags->plus && n >= 0)
		number = ft_printf_signal_flag(number, '+');
	if (flags->precision_flag)
		number = ft_printf_precision(n, number, flags);
	if (flags->space && !flags->plus && n >= 0)
		number = ft_printf_signal_flag(number, ' ');
	if (flags->width)
		number = ft_printf_width(number, flags);
	ft_printf_buffer_add(lst, number, ft_strlen(number));
	free(number);
}
