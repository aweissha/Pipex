/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:30:26 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 16:30:28 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_vars	*vars;
	int		total_processes;

	if (argc >= 5)
	{
		total_processes = 1;
		vars = ft_init_struct(argc, argv, env);
		if (vars->here_doc == 1)
		{
			if (argc < 6)
				ft_free_error("here_doc: wrong number of arguments", 1, vars);
			ft_here_doc(vars);
		}
		ft_fork_recursive(vars, total_processes, NULL);
	}
	else
		ft_error("Wrong number of arguments", 1);
	return (0);
}
