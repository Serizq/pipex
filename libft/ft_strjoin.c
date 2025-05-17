/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:34:56 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/15 17:02:17 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = malloc((len) * sizeof(char));
	if ((!s1) || (!s2))
		return (NULL);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len);
	ft_strlcat(new_string, s2, len);
	return (new_string);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*new_string;

	str1 = "Hola";
	str2 = " Sergio";
	new_string = ft_strjoin(str1, str2);
	printf("%s\n", new_string);
	return (0);
}*/
