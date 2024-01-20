/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:35:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/20 18:05:50 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_heredoc_read(t_vars *vars, int *pipe_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO, 0);
		if (ft_strncmp(vars->argv[2], line, (ft_strlen(line) - 1)) == 0)
			break ;
		write(pipe_fd[1], line, ft_strlen(line));
	}
}

void	ft_here_doc(t_vars *vars)
{
	if (pipe(vars->here_doc_pipe_fd) == -1)
		ft_error("Error opening here_doc pipe", EXIT_FAILURE);
	ft_heredoc_read(vars, vars->here_doc_pipe_fd);
	close(vars->here_doc_pipe_fd[1]);
}

int	ft_is_heredoc(char *str)
{
	if (ft_strcmp("here_doc", str) == 0)
		return (1);
	else
		return (0);
}
