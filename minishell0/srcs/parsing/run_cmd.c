/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:37:45 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 05:37:19 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_cmd(void)
{
	char	*buf;

	while (1)
	{
		buf = readline("minishell > ");
		parsing(buf);
		// run_exec(is_builtin());
		add_history(buf);
		// system("leaks minishell");
	}
}