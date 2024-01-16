/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/16 15:54:05 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int id1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Error opening the pipe");
		id1 = fork();
		if (id1 == -1)
			ft_error("Error forking the parent process");
		if (id1 == 0)
			// child process 1 (first programm)
			ft_child1(argv[1], argv[2], fd, env);
		else
			ft_parent(argv[3], argv[4], fd, env);
		waitpid(id1, NULL, 0);
	}
	else
		ft_error("Wrong number of arguments");
	return (0);
}
