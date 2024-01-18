/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:43:52 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/18 13:18:49 by aweissha         ###   ########.fr       */
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

typedef struct s_vars
{
	char	**argv;
	int		argc;
	char	**env;
	int		*previous_pipe_fd;
}	t_vars;

void	ft_fork_recursive(t_vars *vars, int	total_processes, int *previous_pipe_fd);
t_vars	*ft_init_struct(int argc, char **argv, char **env);
void	ft_last_child(t_vars *vars, int *previous_pipe_fd);
void	ft_middle_child(t_vars *vars, int *pipe_fd, int *previous_pipe_fd, int total_processes);
void	ft_parent(t_vars *vars, int *pipe_fd);
void	ft_execute(char **command_array, char **env);
void	ft_redirect_stdout(char *outfile);
void	ft_redirect_stdin(char *infile);
char	*ft_get_path(char **command_array, char **env);
void	ft_error(char *message);

#endif