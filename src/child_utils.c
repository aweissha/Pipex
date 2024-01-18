/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/18 16:44:01 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_redirect_stdout(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY);
	if (fd == -1)
		ft_error("Error opening outfile");
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	ft_redirect_stdin(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening the infile");
	dup2(fd, STDIN_FILENO);
	close(fd);
}

