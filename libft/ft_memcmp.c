/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:29:49 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/11 19:17:16 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (_s1[i] != _s2[i])
		{
			return (_s1[i] - _s2[i]);
		}
		i++;
	}
	return (0);
}
/*int	main(void)
{
   const char	str_1[] = "42 Madrid";
   const char	str_2[] = "42 Urduliz";
   size_t	len = 10;
   int	result;

   result = ft_memcmp(str_1, str_2, len);
   printf("Difference: %d", result);
   return (0);
}*/
