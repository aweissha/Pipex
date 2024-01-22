/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 15:36:45 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_redirect_stdout(char *outfile, t_vars *vars)
{
	int	fd;

	if (vars->here_doc == 1)
		fd = open(outfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_free_error("Error opening outfile", EXIT_FAILURE, vars);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	ft_redirect_stdin(char *infile, t_vars *vars)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0644);
	if (fd == -1)
		ft_free_error("Error opening infile", EXIT_FAILURE, vars);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

char	*ft_get_path(char **command_array, char **env)
{
	char	**path_array;
	char	*path1;
	char	*path2;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH", ft_strlen(env[i])) != NULL)
			break ;
		i++;
	}
	path_array = ft_split(&env[i][5], ':');
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

void	ft_execute(char **command_array, t_vars *vars)
{
	char	*path;

	path = ft_get_path(command_array, vars->env);
	if (path == NULL)
	{
		ft_free_array(command_array);
		ft_free_error("command not found", 1, vars);
	}
	command_array[0] = path;
	execve(path, command_array, vars->env);
	ft_free_array(command_array);
	free(path);
	ft_free_error("Executing program failed", 1, vars);
}
