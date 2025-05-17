/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:16:34 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/15 18:26:12 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*n_dest;
	unsigned const char	*n_src;

	n_dest = (unsigned char *)dest;
	n_src = (unsigned const char *)src;
	if (n_dest > n_src)
	{
		while (n--)
		{
			n_dest[n] = n_src[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/*
int	main(void)
{
	char ss[15] = "ABCDE";
	char dd[] = "1234";
	size_t aa = 4;

	printf("el memmove da:%s\n", (char*)ft_memmove(ss, dd, aa));
	return(0);
}*/
