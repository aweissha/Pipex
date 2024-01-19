/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:58 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{	
	t_vars	*vars;
	int		total_processes;
	
	total_processes = 1;
	vars = ft_init_struct(argc, argv, env);
	printf("%d\n", vars->here_doc);
	if (argc >= 5)
		ft_fork_recursive(vars, total_processes, NULL);
	else
		ft_error("Wrong number of arguments");
	return (0);
}
