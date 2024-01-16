/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/16 16:21:28 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_get_path(char **command_array, char **env)
{
	char	**path_array;
	char	*path1;
	char	*path2;
	int		i;

	i = 0;
	while(env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH", ft_strlen(env[i])) != NULL);
			break ;
		i++;
	}
	path_array = ft_split(env[i], ':');
	i = 0;
	while (path_array[i] != NULL)
	{
		path1 = ft_strjoin(path_array[i], "/");
		path2 = ft_strjoin(path1, command_array[0]);
		free(path1);
		if (access(path2, X_OK) == 0)
			return (path2);
		else
			i++;
	}
	return (NULL);
}

void	ft_execute_program1(char **command_array, char **env)
{
	char	*path;

	path = ft_get_path(command_array, env);
	command_array[0] = path;
	if (path == NULL)
		ft_error("First command not found in PATH or access denied");
	else
		execve(path, command_array, env);
	free(path);
	ft_error("Executing program command 1 failed");
}

void	ft_redirect_stdin(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening the infile");
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	ft_child2(char *command, char *outfile, int *pipe_fd, char **env)
{
	char **command_array;

	dup2(pipe_fd[0], STDIN_FILENO);				// Define the pipe to be the standard input of this process
	close(pipe_fd[0]);
	close(pipe_fd[1]);	
	command_array = ft_split(command, ' ');		// Take the command string and transform it into an array of strings using ft_split
	ft_redirect_stdout(outfile);				// Open the outfile and redirect the standard output (stdout bzw. 1) to it
	ft_execute_program2(command_array);			// Execute the program and thus output the result to the outfile
}

void	ft_child1(char *infile, char *command, int *pipe_fd, char **env)
{
	char **command_array;

	ft_redirect_stdin(infile);					// Open the file infile and use dup2 to redirect stdin to infile	
	command_array = ft_split(command, ' ');		// Take the command string and transform it into an array of strings using ft_split
	dup2(pipe_fd[1], STDOUT_FILENO);			// Redirect the standard output (stdout bzw. 1) of the process to the pipe
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_execute_program1(command_array, env);	// Execute the program and thus output the result to the pipe
}
