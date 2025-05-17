/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:20:47 by seizquie          #+#    #+#             */
/*   Updated: 2025/04/09 12:21:46 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

void	ft_bubblesort(int *array, int len)
{
	int	flag;
	int	i;
	int	temp;

	flag = 1;
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
}
/*int main()
{
	int	i;
	int	array[8] = {8, 26, -3, 12, 6, 20, -8, 0};

	i = 0;
	ft_bubblesort(array, 8);
	while(i < 8)
	{
		printf("El array ordenado es: %d\n", array[i]);
	i++;
	}
}*/