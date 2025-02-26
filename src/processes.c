/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:32 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/23 11:49:49 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_last_child(t_vars *vars, int *prev_pipe)
{
	char	**command_array;

	if (vars->here_doc == 1 && vars->argc > 5)
	{
		if (dup2(vars->here_doc_pipe_fd[0], STDIN_FILENO) == -1)
			ft_free_error("Error redirecting STDIN", EXIT_FAILURE, vars);
		close(vars->here_doc_pipe_fd[0]);
	}
	else
		ft_redirect_stdin((vars->argv)[1], vars);
	if (dup2(prev_pipe[1], STDOUT_FILENO) == -1)
		ft_free_error("Error redirecting STDOUT", EXIT_FAILURE, vars);
	command_array = ft_split((vars->argv)[2 + vars->here_doc], ' ');
	if (command_array == NULL)
		ft_free_error("ft_split failed", EXIT_FAILURE, vars);
	close(prev_pipe[0]);
	close(prev_pipe[1]);
	ft_execute(command_array, vars);
}

void	ft_child(t_vars *vars, int *pipe_fd, int *prev_pipe, int processes)
{
	char	**command_array;

	if (vars->here_doc != 0)
		close(vars->here_doc_pipe_fd[0]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_free_error("Error redirecting STDIN", EXIT_FAILURE, vars);
	if (dup2(prev_pipe[1], STDOUT_FILENO) == -1)
		ft_free_error("Error redirecting STDOUT", EXIT_FAILURE, vars);
	command_array = ft_split((vars->argv)[(vars->argc) - 1 - processes], ' ');
	if (command_array == NULL)
		ft_free_error("ft_split failed", EXIT_FAILURE, vars);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(prev_pipe[0]);
	close(prev_pipe[1]);
	ft_execute(command_array, vars);
}

void	ft_parent(t_vars *vars, int *pipe_fd)
{
	char	**command_array;

	if (vars->here_doc != 0)
		close(vars->here_doc_pipe_fd[0]);
	ft_redirect_stdout((vars->argv)[(vars->argc) - 1], vars);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_free_error("Error redirecting STDIN", EXIT_FAILURE, vars);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	command_array = ft_split((vars->argv)[(vars->argc) - 2], ' ');
	if (command_array == NULL)
		ft_free_error("ft_split failed", EXIT_FAILURE, vars);
	ft_execute(command_array, vars);
}

void	ft_fork_recursive(t_vars *vars, int processes, int *prev_pipe)
{
	int	fd[2];
	int	id;
	int	processes_left;

	processes_left = (vars->argc) - 3 - processes - vars->here_doc;
	if (processes_left > 0)
	{
		if (pipe(fd) == -1)
			ft_free_error("Error opening pipe", EXIT_FAILURE, vars);
		id = fork();
		if (id == -1)
			ft_free_error("Error forking", EXIT_FAILURE, vars);
		if (id == 0)
			ft_fork_recursive(vars, processes + 1, fd);
		else if (id != 0 && processes == 1)
			ft_parent(vars, fd);
		else
			ft_child(vars, fd, prev_pipe, processes);
	}
	else if (processes_left == 0)
		ft_last_child(vars, prev_pipe);
}
