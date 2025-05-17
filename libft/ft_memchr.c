/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:26:11 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/11 19:17:22 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	ch;

	i = 0;
	string = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == ch)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *string = "Hola que .tal cómo estás?";
	char needle = '.';
	void *ptr;

	ptr = ft_memchr(string, needle, 28);
	printf("La string empezará desde: %s", ptr);
		// La string empezará desde: .tal cómo estás?%

	return (0);
} */
