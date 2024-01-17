/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:43:52 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/17 17:37:11 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"



// void	ft_child2(char *command, char *outfile, int *pipe_fd, char **env);
void	ft_child1(char **argv, int *pipe_fd, char **env);
void	ft_parent(char ** argv, int argc, int *pipe_fd, char **env);
// void	ft_execute_program2(char **command_array, char **env);
void	ft_execute(char **command_array, char **env);
void	ft_redirect_stdout(char *outfile);
void	ft_redirect_stdin(char *infile);
char	*ft_get_path(char **command_array, char **env);
void	ft_error(char *message);

#endif