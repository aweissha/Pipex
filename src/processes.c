/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:32 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/18 14:18:57 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_last_child(t_vars *vars, int *previous_pipe_fd)
{
	char **command_array;
	
	printf("hello from last child\n");

	ft_redirect_stdin((vars->argv)[1]);
	command_array = ft_split((vars->argv)[2], ' ');
	dup2(previous_pipe_fd[1], STDOUT_FILENO);
	close(previous_pipe_fd[0]);
	close(previous_pipe_fd[1]);
	ft_execute(command_array, vars->env);		
}

void	ft_middle_child(t_vars *vars, int *pipe_fd, int *previous_pipe_fd, int total_processes)
{
	char **command_array;

	printf("hello from middle child\n");

	dup2(pipe_fd[0], STDIN_FILENO);
	command_array = ft_split((vars->argv)[(vars->argc) - 1 - total_processes], ' ');				// Take the command string and transform it into an array of strings using ft_split
	dup2(previous_pipe_fd[1], STDOUT_FILENO);														// Redirect the standard output (stdout bzw. 1) of the process to the pipe
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(previous_pipe_fd[0]);
	close(previous_pipe_fd[1]);
	ft_execute(command_array, vars->env);															// Execute the program and thus output the result to the pipe
}

void	ft_parent(t_vars *vars, int *pipe_fd)
{
	char **command_array;

	printf("hello from parent\n");
	
	dup2(pipe_fd[0], STDIN_FILENO);						// Define the pipe to be the standard input of this process
	close(pipe_fd[0]);
	close(pipe_fd[1]);	
	command_array = ft_split((vars->argv)[(vars->argc) - 2], ' ');		// Take the command string and transform it into an array of strings using ft_split
	ft_redirect_stdout((vars->argv)[(vars->argc) - 1]);					// Open the outfile and redirect the standard output (stdout bzw. 1) to it
	ft_execute(command_array, vars->env);						// Execute the program and thus output the result to the outfile
}

void	ft_fork_recursive(t_vars *vars, int	total_processes, int *previous_pipe_fd)
{
	int	fd[2];
	int id;
	int	processes_left;

	printf("process %d\n", total_processes);
	
	processes_left = (vars->argc) - 3 - total_processes;
	if (processes_left > 0)
	{
		if (pipe(fd) == -1)
			ft_error("Error opening the first pipe");
		id = fork();
		if (id == -1)
			ft_error("Error forking the parent process");
		if (id == 0)
			ft_fork_recursive(vars, total_processes + 1, fd);
		else if (id != 0 && total_processes == 1)
			ft_parent(vars, fd);
		else
			ft_middle_child(vars, fd, previous_pipe_fd, total_processes);
	}
	else if (processes_left == 0)
		ft_last_child(vars, previous_pipe_fd);
}
