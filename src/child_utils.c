/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/19 10:01:07 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_redirect_stdout(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT,  0644); // O_APPEND fuer here_doc
	if (fd == -1)
		ft_error("Error opening outfile");
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	ft_redirect_stdin(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0644);
	if (fd == -1)
		ft_error("Error opening the infile");
	dup2(fd, STDIN_FILENO);
	close(fd);
}

