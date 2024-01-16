/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:48:04 by aweissha          #+#    #+#             */
/*   Updated: 2024/01/15 13:08:01 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int main(void)
{
	int	arr[10];
	int	n;
	int	*ptr = arr;

	n = 42;
	printf("%p\n", arr);
	printf("%p\n", ptr);
	printf("%lu\n", sizeof(arr));
	printf("%lu\n", sizeof(ptr));
	printf("%lu\n", sizeof(n));
	printf("%lu\n", sizeof(&n));
}
