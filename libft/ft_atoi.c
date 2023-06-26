/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:34:33 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 20:09:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c > 8 && c < 14));
}

/* Converts the inital part of num_str to int */
int	ft_atoi(const char *num_str)
{
	int				i;
	unsigned int	result;
	int				num_signal;

	num_signal = 1;
	result = 0;
	i = 0;
	while (ft_isspace(num_str[i]))
		i++;
	if (num_str[i] == '-' || num_str[i] == '+')
	{
		if (num_str[i] == '-')
			num_signal = -1;
		i++;
	}
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		result = result * 10 + (num_str[i] - '0');
		i++;
	}
	return (result * num_signal);
}
