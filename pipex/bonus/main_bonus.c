/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:08:58 by pjang             #+#    #+#             */
/*   Updated: 2022/11/07 21:14:11 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	int		fd;
	t_data	data;

	if (argc < 5)
		put_error("bash: pipex: Too few arguments", NULL);
	init(argc, &data, envp);
	parsing(argc, argv, &data);
	if (ft_memcmp(argv[1], "here_doc", 9) == 0 && argc > 5)
	{
		fd = here_doc(&data);
		close(fd);
		safety_free(data.red_lto->token, NULL);
		data.red_lto->token = ft_strdup(data.red_hrd->filename);
	}
	pipex(&data, 0, envp, 0);
	return (EXIT_SUCCESS);
}
