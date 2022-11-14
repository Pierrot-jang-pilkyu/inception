/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:51:02 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:32:57 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		if (data->philo[i].eat_flag == 0)
			return (0);
		i++;
	}
	i = 0;
	pthread_mutex_lock(&data->dead_mutex);
	data->esc_eat = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	return (1);
}

int	check_dead2(t_data *data, int i)
{
	time_t	time;

	time = (get_time() - data->philo[i].last_eat) / 1000;
	if (time >= data->time_to_die)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->dead = 1;
		print_message(&data->philo[i], 5);
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*check_dead(void *arg)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	while (1)
	{
		if (i == data->number)
			i = 0;
		pthread_mutex_lock(&data->eat_mutex);
		if (check_dead2(data, i))
			break ;
		if (check_eat(data))
			break ;
		pthread_mutex_unlock(&data->eat_mutex);
		i++;
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (NULL);
}

int	check(t_data *data, int n)
{
	int				tid;

	if (n == 1)
	{
		tid = pthread_create(&data->thread, NULL, check_dead, (void *)data);
		if (tid < 0)
			return (put_error("thread create error.\n"));
	}
	if (n == 2)
		pthread_join(data->thread, NULL);
	return (0);
}
