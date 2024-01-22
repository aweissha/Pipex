/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:43:52 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 15:09:19 by aweissha         ###   ########.fr       */
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
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_vars
{
	char	**argv;
	int		argc;
	char	**env;
	int		here_doc;
	int		here_doc_pipe_fd[2];
}	t_vars;

void	ft_fork_recursive(t_vars *vars, int processes, int *prev_pipe);
t_vars	*ft_init_struct(int argc, char **argv, char **env);
void	ft_last_child(t_vars *vars, int *prev_pipe);
void	ft_child(t_vars *vars, int *pipe_fd, int *prev_pipe, int processes);
void	ft_parent(t_vars *vars, int *pipe_fd);
void	ft_execute(char **command_array, t_vars *vars);
void	ft_redirect_stdout(char *outfile, t_vars *vars);
void	ft_redirect_stdin(char *infile, t_vars *vars);
char	*ft_get_path(char **command_array, char **env);
void	ft_error(char *message, int code);
int		ft_is_heredoc(char *str);
void	ft_heredoc_read(t_vars *vars, int *pipe_fd);
void	ft_here_doc(t_vars *vars);
void	ft_free_array(char **array);
void	ft_free_error(char *message, int code, t_vars *vars);

#endif