/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/17 18:21:01 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_execute(char **command_array, char **env)
{
	char	*path;

	path = ft_get_path(command_array, env);
	if (path == NULL)
		ft_error("Program not found in PATH or access denied");
	command_array[0] = path;
	execve(path, command_array, env);
	free(path);
	ft_error("Executing program failed");
}

void	ft_parent(char **argv, int argc, int *pipe_fd, char **env)
{
	char **command_array;

	dup2(pipe_fd[0], STDIN_FILENO);						// Define the pipe to be the standard input of this process
	close(pipe_fd[0]);
	close(pipe_fd[1]);	
	command_array = ft_split(argv[argc - 2], ' ');		// Take the command string and transform it into an array of strings using ft_split
	ft_redirect_stdout(argv[argc - 1]);					// Open the outfile and redirect the standard output (stdout bzw. 1) to it
	ft_execute(command_array, env);						// Execute the program and thus output the result to the outfile
}

void	ft_fork_recursive(char **argv, int *pipe_fd, int commands_left, char **env)
{
	int	fd[2];
	int id;

	if (commands_left == 1)
		ft_last_child(argv, fd, pipe_fd, env);
	else if (commands_left > 1)
	{
		if (pipe(fd) == -1)
			ft_error("Error opening the first pipe");
		id = fork();
		if (id == -1)
			ft_error("Error forking the parent process");
		if (id == 0)
			ft_fork_recursive(argv, fd, commands_left - 1, env);
		else
			ft_middle_child(argv, fd, pipe_fd, env);		
	}
}

void	ft_fork_algorithm(char **argv, int argc, char **env)
{
	int	fd[2];
	int id1;
	int	commands_left;
	
	commands_left = argc - 3;
	if (pipe(fd) == -1)
		ft_error("Error opening the first pipe");
	id1 = fork();
	if (id1 == -1)
		ft_error("Error forking the parent process");
	if (id1 == 0)
		ft_fork_recursive(argv, fd, commands_left - 1, env);
	else
		ft_parent(argv, argc, fd, env);
}



	// if (commands_left == 2)
	// {
	// 	ft_last_child();
	// }
	// else if (commands_left > 2)
	// {
	// 	ft_middle_child();
	// 	ft_fork_algorithm();
	// }






int	main(int argc, char **argv, char **env)
{	

	if (argc >= 5)
		ft_fork_algorithm(argv, argc, env);
	else
		ft_error("Wrong number of arguments");
	return (0);
}
