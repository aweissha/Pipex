/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:32 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/16 14:18:00 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_parent(char *command, char *outfile, int *pipe_fd, char **env)
{
	int	id2;
	
	id2 = fork();
	if (id2 == -1)
		ft_error("Error at second fork of the parent process");
	if (id2 == 0)
		// Child process 2 (for executing the second program)
		ft_child2(command, outfile, pipe_fd, env);
	else
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(id2, NULL, 0);		
	}
}
