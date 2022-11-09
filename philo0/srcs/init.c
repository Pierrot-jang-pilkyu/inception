/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:11:21 by pjang             #+#    #+#             */
/*   Updated: 2022/11/09 19:10:26 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number);
	if (!data->philo)
		return (put_error("data->philo malloc error.\n"));
	i = 0;
	while (i < data->number)
	{
		if (i == data->number - 1)
			data->philo[i].right_fork = &data->philo[0].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
		data->philo[i].eat_flag = 0;
		i++;
	}
	data->p_num = -1;
	data->dead = 0;
	return (0);
}
