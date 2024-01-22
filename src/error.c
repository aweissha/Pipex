/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:36:48 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/22 15:01:43 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(char *message, int code)
{
	perror(message);
	exit(code);
}

void	ft_free_error(char *message, int code, t_vars *vars)
{
	free(vars);
	ft_error(message, code);
}
