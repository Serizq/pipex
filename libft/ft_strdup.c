/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:31:26 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 17:46:57 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_string;
	size_t	s_len;

	s_len = ft_strlen(s);
	duplicated_string = (char *)malloc((s_len + 1) * sizeof(char));
	if (!duplicated_string)
		return (NULL);
	duplicated_string = ft_memcpy(duplicated_string, s, s_len);
	duplicated_string[s_len] = '\0';
	return (duplicated_string);
}
