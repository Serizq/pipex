/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:15:51 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/15 18:38:04 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t				i;
	unsigned char		*n_dest;
	unsigned const char	*n_src;

	i = 0;
	n_dest = (unsigned char *)dest;
	n_src = (unsigned const char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		n_dest[i] = n_src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	a[4] = "abc";
	char	b[4];

	printf("ft_memcpy:%s\n", (char*) ft_memcpy(b, a, 4));
	printf("b after ft_memcpy: %s\n", b);
	printf("a:%s\n", a);
	return(0);
}
*/
