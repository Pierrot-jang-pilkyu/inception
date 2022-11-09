/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:26:10 by pjang             #+#    #+#             */
/*   Updated: 2022/11/09 19:11:18 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_time(time_t time)
{
	char	c;

	if (time > 9)
	{
		put_time(time / 10);
		put_time(time % 10);
	}
	else
	{
		c = time + '0';
		write(1, &c, 1);
	}
}

void	timestamp(t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	put_time((philo->now.tv_usec - philo->start.tv_usec) / 1000);
	write(1, " ms ", 4);
}

void	*table(void *arg)
{
	int		idx;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data->philo;
	idx = data->p_num;
	while (1)
	{
		if (check_dead(data, idx))
		{
			data->dead = 1;
			break ;
		}
		pthread_mutex_lock(&philo[idx].left_fork);
		pthread_mutex_lock(philo[idx].right_fork);
		philo[idx].eat_flag = 1;
		taken_a_fork(data, idx);
		is_eating(data, idx);
		pthread_mutex_unlock(&philo[idx].left_fork);
		pthread_mutex_unlock(philo[idx].right_fork);
		usleep(200);
		if (is_sleeping(data, idx))
			break ;
		if (is_thinking(data, idx))
			break ;
	}
}

int	philo(t_data *data)
{
	int	i;
	int	tid;

	i = -1;
	while (++i < data->number)
	{
		data->p_num = i + 1;
		pthread_mutex_init(&data->philo->left_fork, NULL);
		pthread_mutex_init(data->philo->right_fork, NULL);
		gettimeofday(&data->philo->start, NULL);
		tid = pthread_create(&data->philo[i].thread, \
				NULL, table, (void *)data);
		if (tid < 0)
			return (put_error("thread create error.\n"));
		pthread_detach(data->philo[i].thread);
	}
	return (0);
}
