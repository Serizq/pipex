/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:52:32 by seizquie          #+#    #+#             */
/*   Updated: 2025/05/19 18:56:09 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == INFILE)
		fd = open(file, O_RDONLY);
	else if (mode == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
	{
		return (-1); // Nunca se ejecutará, por el exit en ft_error
	}
	if (fd == -1)
		ft_error("Error opening file\n", 1);
	return (fd);
}

