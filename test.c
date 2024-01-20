/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:48:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/20 11:12:44 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	int i = 0;
	while (i < 1)
	{
		line = get_next_line(STDIN_FILENO, 0);
		printf("%s", line);
		// printf("%c", line[1]);
		// printf("%c", line[2]);
		i++;
	}
}
