/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:13:03 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/14 18:14:26 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	ft_check_base(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]) || ft_strcntchr(base, base[i]) > 1)
			return (0);
		i++;
	}
	return (i);
}

static void	ft_putdigit(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str);
	str[i] = c;
}

static void	ft_utoa_base_r(unsigned long int n, char *number,
		char *base, unsigned int size)
{
	if (n >= size)
		ft_utoa_base_r(n / size, number, base, size);
	ft_putdigit(number, base[n % size]);
}

static char	*ft_custom_str(char *number)
{
	char	*new;

	new = ft_strdup(number);
	if (!new)
		return (number);
	free(number);
	return (new);
}

/* Returns a string representing the unsigned long integer n in base base 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
char	*ft_ultoa_base(unsigned long int n, char *base)
{
	char			*number;
	unsigned int	base_size;

	base_size = ft_check_base(base);
	if (base_size < 2)
		return (NULL);
	number = ft_calloc(64, sizeof(char));
	if (!number)
		return (NULL);
	ft_utoa_base_r(n, number, base, base_size);
	return (ft_custom_str(number));
}
