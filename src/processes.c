/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:32 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/17 17:29:46 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"




void	ft_child1(char **argv, int *pipe_fd, char **env)
{
	char **command_array;

	ft_redirect_stdin(argv[1]);					// Open the file infile and use dup2 to redirect stdin to infile
	command_array = ft_split(argv[2], ' ');		// Take the command string and transform it into an array of strings using ft_split
	dup2(pipe_fd[1], STDOUT_FILENO);			// Redirect the standard output (stdout bzw. 1) of the process to the pipe
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_execute_program1(command_array, env);	// Execute the program and thus output the result to the pipe
}