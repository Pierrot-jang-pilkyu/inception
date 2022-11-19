/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:26:29 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 11:35:04 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

u_int64_t	ft_pow(u_int64_t num, u_int64_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (num * ft_pow(num, power - 1));
}
