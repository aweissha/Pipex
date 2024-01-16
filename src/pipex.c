/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/10 13:29:30 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Error opening the pipe");
		id = fork();
		if (id == -1)
			ft_error("Error forking the parent process");
		if (id == 0)
			ft_child(argv[1], argv[2], fd);
		if (id != 0)
			ft_parent(argv[3], argv[4], fd);
		wait(NULL);
	}
	else
		ft_error("Wrong number of arguments");
	return (0);
}


/*
Plan:
- research. watch all code vault videos.
- Analyze input. Get the names of the infile and outfile as strings.

- Write functions for the commands that will be implemented.

*/