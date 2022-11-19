/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:09:18 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 13:22:59 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	// char	*str;

	// while (1)
	// {
	// 	str = readline(">");
	// 	// int i = rl_on_new_line();
	// 	// printf("%d\n", i);
	// 	// rl_replace_line("bash: ", 0);
	// 	if (str)
	// 	{
	// 		char *temp = ft_substr(str, 0, 2);
	// 		char *buf;
	// 		// buf = (char *)malloc(sizeof(char) * 1000);
	// 		if (ft_memcmp(temp, "cd", 3) == 0)
	// 		{
	// 			buf = getcwd(NULL, 0);
	// 			printf("buf : %s\n", buf);
	// 			char *t1 = ft_strjoin(buf, "/");
	// 			char *path = ft_strjoin(t1, (str + 3));
	// 			printf("path : %s\n", path);
	// 			chdir(path);
	// 		}
	// 		free(temp);
	// 		free(buf);
	// 	}
	// 	else
	// 		break ;
	// 	free(str);
	// }
	printf("%d\n", '\"');
	printf("%d\n", '\'');
	printf("%d\n", '&');
	printf("%d\n", '|');
	printf("%d\n", '(');
	printf("%d\n", ')');
	printf("%d\n", '<');
	printf("%d\n", '>');
	return (0);
}
