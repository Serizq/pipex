#include "pipex.h"

void	fork_child_one(pid_t *pid, int *pipefd, char **argv, char **envp, int infile)
{
	*pid = fork();
	if (*pid == -1)
		pipex_error("Error forking child1\n", 1);
	if (*pid == 0)
		child_one(pipefd, argv, envp, infile);
}

void	fork_child_two(pid_t *pid, int *pipefd, char **argv, char **envp, int outfile)
{
	*pid = fork();
	if (*pid == -1)
		pipex_error("Error forking child2\n", 1);
	if (*pid == 0)
		child_two(pipefd, argv, envp, outfile);
}
