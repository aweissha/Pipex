/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/17 17:36:23 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_execute_program2(char **command_array, char **env)
{
	char	*path;

	path = ft_get_path(command_array, env);
	if (path == NULL)
		ft_error("Second command not found in PATH or access denied");
	command_array[0] = path;
	execve(path, command_array, env);
	free(path);
	ft_error("Executing program command 2 failed");
}

void	ft_redirect_stdout(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY);
	if (fd == -1)
		ft_error("Error opening outfile");
	dup2(fd, STDOUT_FILENO);
	close(fd);
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

