/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:08:58 by pjang             #+#    #+#             */
/*   Updated: 2022/10/18 11:57:40 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	if (argc > 4)
	{
		init(argc, &data, envp);
		parsing(argc, argv, &data);
		pipex(&data, 0, envp);
		data_free(&data);
	}
	else
		put_error(STDERR_FILENO, "bash: pipex: Too few arguments");
	return (EXIT_SUCCESS);
}
