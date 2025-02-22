/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:01 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 16:46:38 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
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
	if (ft_is_heredoc(argv[1]) == 1 && argc > 5)
		vars->here_doc = 1;
	else
		vars->here_doc = 0;
	return (vars);
}

int	ft_is_heredoc(char *str)
{
	if (ft_strcmp("here_doc", str) == 0)
		return (1);
	else
		return (0);
}
