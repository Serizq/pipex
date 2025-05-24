/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:00:41 by seizquie          #+#    #+#             */
/*   Updated: 2025/05/19 18:40:58 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INFILE 0
# define OUTFILE 1

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>


//pipex.c
int	open_file(char *file, int mode);
void	child_one(int *pipefd, char **argv, char **envp, int infile);
void	child_two(int *pipefd, char **argv, char **envp, int outfile);
int	main(int argc, char **argv, char **envp);

//pipex_utils.c
char	*ft_getenv(const char *name, char **envp);
char	*get_path(char *cmd, char **envp);
void	pipex_error(char *str, int exit_code);

//main_utils.c
void	fork_child_one(pid_t *pid, int *pipefd, char **argv, char **envp, int infile);
void	fork_child_two(pid_t *pid, int *pipefd, char **argv, char **envp, int outfile);














#endif
