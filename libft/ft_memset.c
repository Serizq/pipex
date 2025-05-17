/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:07:42 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/14 19:50:43 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char )c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char	str[] = "Sergio 42";
	char	c = 'a';
	size_t	len = 6;

	printf("Original text: %s\n",str);
	ft_memset(str, c, len);
	printf("Final text: %s\n", str);
	return (0);
}*/
