/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:08:58 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 19:43:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	if (argc < 5)
		put_error("bash: pipex: Too few arguments", NULL);
	if (argc > 5)
		put_error("bash: pipex: Too many arguments", NULL);
	init(argc, &data, envp);
	parsing(argc, argv, &data);
	pipex(&data, 0, envp);
	return (EXIT_SUCCESS);
}
