/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:26:10 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:33:43 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_one(t_philo *philo)
{
	taken_a_fork(philo);
	while (1)
	{
		if (*philo->dead)
			break ;
	}
}

void	be_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	taken_a_fork(philo);
	pthread_mutex_lock(philo->right_fork);
	taken_a_fork(philo);
	is_eating(philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	is_sleeping(philo);
	is_thinking(philo);
}

void	*table(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->p_num % 2 == 0)
	{
		is_thinking(philo);
		ft_sleep(philo->input[T_EAT] / 4);
	}
	while (1)
	{
		pthread_mutex_lock(philo->dead_mutex);
		if (*philo->dead || *philo->esc_eat)
			break ;
		pthread_mutex_unlock(philo->dead_mutex);
		if (philo->input[HEADS] == 1)
			philo_one(philo);
		else
			be_philo(philo);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (NULL);
}

int	philo(t_data *data)
{
	int			i;
	int			tid;
	u_int64_t	start;

	i = -1;
	check(data, 1);
	start = get_time();
	while (++i < data->number)
	{
		data->philo[i].p_num = i + 1;
		data->philo[i].start = start;
		pthread_mutex_lock(&data->eat_mutex);
		data->philo[i].last_eat = start;
		pthread_mutex_unlock(&data->eat_mutex);
		tid = pthread_create(&data->philo[i].thread, \
				NULL, table, (void *)&data->philo[i]);
		if (tid < 0)
			return (put_error("thread create error.\n"));
	}
	i = -1;
	while (++i < data->number)
		pthread_join(data->philo[i].thread, NULL);
	check(data, 2);
	return (0);
}
