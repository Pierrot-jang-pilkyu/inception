/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:36:57 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 14:39:11 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree	*new_tree(int key, char *value)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(t_tree) * 1);
	if (!new)
		put_error(strerror(errno));
	new->key = key;
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	get_depth(unsigned int idx)
{
	int	pow;

	pow = 1;
	while (1)
	{
		if (idx < ft_pow(2, pow))
			break ;
		pow++;
	}
	return (pow);
}

int	*get_path(int idx)
{
	int	num;
	int	pow;
	int	depth;
	int	*res;

	num = 1;
	pow = 0;
	depth = get_depth((unsigned int)idx);
	res = (int *)malloc(sizeof(int) * (depth + 1));
	while (num > 0)
	{
		num = idx / ft_pow(2, pow++);
		res[depth--] = num % 2;
	}
	res[depth] = -1;
	return (res);
}

/*
				1
			2		  3
		4	  5     6	  7
	  8	 9  10 11 12 13 14  15
	16 17 ...

	parent = n, left = 2n, right = 2n + 1;
	depth = l, 2^l - 1 th
*/
void	add_tree(t_tree **tree, int idx, t_tree *newtree)
{
	int		i;
	int		*path;
	t_tree	*temp;

	if (*tree == NULL || idx == 1)
	{
		*tree = newtree;
		return ;
	}
	if (newtree == NULL)
		return ;
	temp = *tree;
	path = get_path(idx);
	i = 0;
	while (path[++i + 1] != -1)
	{
		if (path[i] == 0)
			temp = temp->left;
		else if (path[i] == 1)
			temp = temp->right;
	}
	if (path[i] == 0)
		temp->left = newtree;
	else if (path[i] == 1)
		temp->right = newtree;
}
