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

void	child_one(int *pipefd, char **argv, char **envp, int infile)
{
	char	**cmd_args;
	char	*cmd_path;

	if (!argv[2] || argv[2][0] == '\0')
		pipex_error("First command is empty", 127);
	if (dup2(infile, STDIN_FILENO) == -1) // Redirecciona la entrada desde el archivo infile
		pipex_error("Error duplicating infile\n", 1);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1) 	// Redirecciona la salida al pipe
		pipex_error("Error duplicating pipe write end\n", 1);
	close(pipefd[0]); // Cierra extremos innecesarios del pipe. pipefd[0]No se usa en child_one
	close(pipefd[1]);
	close(infile);
	cmd_args = ft_split(argv[2], ' '); // Divide el comando y busca su path
	if (!cmd_args)
		pipex_error("Error splitting command 1\n", 1);
	cmd_path = get_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		ft_free_array(cmd_args);
		pipex_error("Command not found (child_one)\n", 127);
	}
	execve(cmd_path, cmd_args, envp);
	ft_free_array(cmd_args); // Si execve falla
	free(cmd_path);
	pipex_error("Execution failed (child_one)\n", 126);
}

void	child_two(int *pipefd, char **argv, char **envp, int outfile)
{
	char	**cmd_args;
	char	*cmd_path;

	if (!argv[3] || argv[3][0] == '\0')
		pipex_error("Second command is empty", 127);
	if(dup2(pipefd[0], STDIN_FILENO) == -1)
		pipex_error("Error duplicating pipe read end\n", 1);
	if(dup2(outfile, STDOUT_FILENO) == -1)
		pipex_error("Error duplicating outfile\n", 1);
	close(pipefd[1]);
	close(pipefd[0]);
	close(outfile);
	cmd_args = ft_split(argv[3], ' ');
	if (!cmd_args)
		pipex_error("Error splitting command 2\n", 1);
	cmd_path = get_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		ft_free_array(cmd_args);
		pipex_error("Command not found (child_two)", 127);
	}
	execve(cmd_path, cmd_args, envp);
	ft_free_array(cmd_args);
	free(cmd_path);
	pipex_error("Execution failed (child_two)", 126);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infile;
	int	outfile;
	pid_t	child1;
	pid_t	child2;

	if(argc == 5)
	{
		infile = open_file(argv[1], INFILE);
		outfile = open_file(argv[4], OUTFILE);
		if(pipe(pipefd) == -1)
			pipex_error("Error creating pipe\n", 1);
		fork_child_one(&child1, pipefd, argv, envp, infile);
		fork_child_two(&child2, pipefd, argv, envp, outfile);
		close(pipefd[0]);
		close(pipefd[1]);
		wait(NULL);
		wait(NULL);
		return (0);
	}
	else
		pipex_error("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
}
