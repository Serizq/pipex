/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:14:53 by seizquie          #+#    #+#             */
/*   Updated: 2025/04/09 12:19:36 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *str, t_bool e)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	if (e)
		exit(EXIT_FAILURE);
}
