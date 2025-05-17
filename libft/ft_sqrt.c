/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:03:32 by seizquie          #+#    #+#             */
/*   Updated: 2025/04/09 12:22:20 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nmb)
{
	int	i;

	if (nmb < 0)
		return (-1);
	if (nmb < 4)
		return (1);
	i = 2;
	while (i * i < nmb)
		i++;
	if (i * i - nmb < nmb - (i - 1) * (i - 1))
		return (i);
	return (i - 1);
}
