/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:35:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 17:47:08 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_heredoc_read(t_vars *vars, int *pipe_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO, 0);
		if (line == NULL)
			ft_free_error("Get_next_line error", EXIT_FAILURE, vars);
		if (ft_strncmp(vars->argv[2], line, (ft_strlen(line) - 1)) == 0
			&& ft_strncmp(vars->argv[2], line, (ft_strlen(vars->argv[2]))) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	ft_here_doc(t_vars *vars)
{
	if (pipe(vars->here_doc_pipe_fd) == -1)
		ft_free_error("Error opening here_doc pipe", EXIT_FAILURE, vars);
	ft_heredoc_read(vars, vars->here_doc_pipe_fd);
	close(vars->here_doc_pipe_fd[1]);
}
