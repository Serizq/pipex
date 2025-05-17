/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:07:42 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/15 16:46:00 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*n_string;
	int		len;
	long	n_copy;

	n_copy = (long)n;
	len = count_digits(n);
	n_string = (char *)malloc((len + 1) * sizeof(char));
	if (!n_string)
		return (NULL);
	if (n < 0)
	{
		n_copy = -n_copy;
	}
	n_string[len--] = '\0';
	while (len >= 0)
	{
		n_string[len] = n_copy % 10 + '0';
		n_copy = n_copy / 10;
		len--;
	}
	if (n < 0)
		n_string[0] = '-';
	return (n_string);
}
/*
int	main(void)
{
	printf ("Número en carácteres: '%s'.\n", ft_itoa(12));
	return (0);
}*/