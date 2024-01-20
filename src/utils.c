/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:01 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:28 by aweissha         ###   ########.fr       */
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

void	ft_execute(char **command_array, char **env)
{
	char	*path;

	path = ft_get_path(command_array, env);
	if (path == NULL)
		ft_error("command not found", 127);
	command_array[0] = path;
	execve(path, command_array, env);
	free(path);
	ft_error("Executing program failed", 1);
}

t_vars	*ft_init_struct(int argc, char **argv, char **env)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		ft_error("Memory allocation for struct failed", 1);
	vars->argc = argc;
	vars->argv = argv;
	vars->env = env;
	if (ft_is_heredoc(argv[1]) == 1)
		vars->here_doc = 1;
	else
		vars->here_doc = 0;
	return (vars);
}
