/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:52:32 by seizquie          #+#    #+#             */
/*   Updated: 2025/05/20 12:23:05 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == INFILE)
		fd = open(file, O_RDONLY);
	else if (mode == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // lectura escritura para propietario, solo lectura resto
	else
	{
		return (-1); // Nunca se ejecutará, por el exit en ft_error
	}
	if (fd == -1)
		pipex_error("Error opening file\n", 1);
	return (fd);
}
void	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		pipex_error("Error: split failed", 1);
	path = get_path(split_cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_array(split_cmd);
		exit(127);
	}
	execve(path, split_cmd, envp);
	ft_putstr_fd("Error executing command: ", 2);
	ft_putendl_fd(split_cmd[0], 2);
	ft_free_array(split_cmd);
	free(path);
	exit(126);
}

void	child_one(int *pipefd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		pipex_error("Error opening infile", 1);
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	exec_cmd(argv[2], envp);
}

void	child_two(int *pipefd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		pipex_error("Error opening outfile", 1);
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfile);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	child1;
	pid_t	child2;

	if (argc != 5)
		pipex_error("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
	if (pipe(pipefd) == -1)
		pipex_error("Error creating pipe", 1);
	child1 = fork();
	if (child1 == -1)
		pipex_error("Error forking child_one", 1);
	if (child1 == 0)
		child_one(pipefd, argv, envp);
	child2 = fork();
	if (child2 == -1)
		pipex_error("Error forking child_two", 1);
	if (child2 == 0)
		child_two(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
