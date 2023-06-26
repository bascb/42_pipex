/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:26 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:58:46 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

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

static char	*ft_printf_precision(char *str, char *original, t_flags *flags)
{
	char	*new;

	if (!str && flags->precision < 6)
	{
		new = ft_strdup("");
		free(original);
		return (new);
	}
	if (flags->precision >= (int ) ft_strlen(original))
	{
		new = ft_strdup(original);
		free(original);
		return (new);
	}
	new = ft_calloc(flags->precision + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, original, flags->precision + 1);
	free(original);
	return (new);
}

void	ft_printf_str(char *str, t_flags *flags, t_list **lst)
{
	char	*new;

	if (!str)
		new = ft_strdup("(null)");
	else if (!ft_strlen(str))
		new = ft_strdup("");
	else
		new = ft_strdup(str);
	if (flags->precision_flag)
		new = ft_printf_precision(str, new, flags);
	if (flags->width)
		new = ft_printf_width(new, flags);
	ft_printf_buffer_add(lst, new, ft_strlen(new));
	free(new);
}
