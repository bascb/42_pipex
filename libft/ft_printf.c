/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:28:30 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/11 17:59:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer_add(t_list **lst, char *str, size_t size);

int		ft_printf_buffer_output(t_list **lst);

void	ft_printf_str(char *str, t_flags *flags, t_list **lst);

void	ft_printf_chr(char c, t_flags *flags, t_list **lst);

void	ft_printf_int(int n, t_flags *flags, t_list **lst);

void	ft_printf_uns(unsigned int n, t_flags *flags, t_list **lst);

void	ft_printf_hex(int n, t_flags *flags, t_list **lst, char c);

void	ft_printf_pointer(unsigned long int n, t_flags *flags, t_list **lst);

static void	ft_get_precision(char *s, char *f, t_flags *flags)
{
	char	*end;

	end = f;
	if (*end != '.')
	{
		flags->length = end - s;
		return ;
	}
	flags->precision_flag = 1;
	end++;
	flags->precision = ft_atoi(end);
	while (ft_charinset(*end, "0123456789"))
		end++;
	flags->length = end - s;
}

static t_flags	*ft_get_flags(char *f)
{
	char	*end;
	char	*flags_set;
	int		i;
	int		*start;
	t_flags	*flags;

	flags_set = "+ #-0";
	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	end = f;
	start = &(flags->plus);
	while (ft_charinset(*end, flags_set))
	{
		i = -1;
		while (++i < 5)
			if (*end == flags_set[i])
				start[i] = 1;
		end++;
	}
	flags->width = ft_atoi(end);
	while (ft_charinset(*end, "0123456789"))
		end++;
	ft_get_precision(f, end, flags);
	return (flags);
}

static char	*ft_print_conversion(char *f, t_list **lst, va_list	*arguments)
{
	t_flags	*flags;
	int		f_size;
	int		step;

	flags = ft_get_flags(f + 1);
	f_size = flags->length;
	step = 2 + f_size;
	if (*(f + 1 + f_size) == 's')
		ft_printf_str(va_arg(*arguments, char *), flags, lst);
	else if (*(f + 1 + f_size) == 'c')
		ft_printf_chr(va_arg(*arguments, int), flags, lst);
	else if (*(f + 1 + f_size) == 'i' || *(f + 1 + f_size) == 'd')
		ft_printf_int(va_arg(*arguments, int), flags, lst);
	else if (*(f + 1 + f_size) == 'u')
		ft_printf_uns(va_arg(*arguments, unsigned int), flags, lst);
	else if (*(f + 1 + f_size) == 'x' || *(f + 1 + f_size) == 'X')
		ft_printf_hex(va_arg(*arguments, int), flags, lst, *(f + 1 + f_size));
	else if (*(f + 1 + f_size) == 'p')
		ft_printf_pointer(va_arg(*arguments, unsigned long int), flags, lst);
	else if (*(f + 1 + f_size) == '%')
		ft_printf_buffer_add(lst, f + 1 + f_size, 1);
	else
		step = 1;
	free(flags);
	return (f + step);
}

/* Recreation of printf by 42 */
int	ft_printf(const char *format, ...)
{
	t_list	**buffer_lst;
	char	*f;
	va_list	arguments;

	va_start(arguments, format);
	buffer_lst = ft_calloc(1, sizeof(t_list *));
	if (!buffer_lst)
		return (-1);
	f = (char *) format;
	while (*f)
	{
		if (*f == '%')
			f = ft_print_conversion(f, buffer_lst, &arguments);
		else
		{
			ft_printf_buffer_add(buffer_lst, f, 1);
			f++;
		}
	}
	va_end(arguments);
	return ((int) ft_printf_buffer_output(buffer_lst));
}
