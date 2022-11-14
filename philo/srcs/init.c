/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:11:21 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:15:22 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	i = 0;
	while (i < data->number)
		pthread_mutex_init(&data->philo[i++].left_fork, NULL);
}

void	init_input(t_data *data, int i)
{
	data->philo[i].eat_flag = 0;
	data->philo[i].eat_num = 0;
	data->philo[i].last_eat = get_time();
	data->philo[i].p_num = 0;
	data->philo[i].dead = &data->dead;
	data->philo[i].esc_eat = &data->esc_eat;
	data->philo[i].input[HEADS] = data->number;
	data->philo[i].input[T_DIE] = data->time_to_die;
	data->philo[i].input[T_EAT] = data->time_to_eat;
	data->philo[i].input[T_SLEEP] = data->time_to_sleep;
	data->philo[i].input[M_EAT] = data->must_eat;
}

int	init(t_data *data)
{
	int	i;

	data->dead = 0;
	data->esc_eat = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * (data->number));
	if (!data->philo)
		return (put_error("data->philo malloc error.\n"));
	i = 0;
	init_mutex(data);
	while (i < data->number)
	{
		if (i == data->number - 1)
			data->philo[i].right_fork = &data->philo[0].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
		data->philo[i].print_mutex = &data->print_mutex;
		data->philo[i].dead_mutex = &data->dead_mutex;
		data->philo[i].eat_mutex = &data->eat_mutex;
		init_input(data, i);
		i++;
	}
	return (0);
}
