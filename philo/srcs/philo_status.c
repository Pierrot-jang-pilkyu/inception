/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:43:47 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:18:20 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = get_time();
	while (get_time() - start <= time * 1000)
	{
		usleep(100);
	}
}

void	taken_a_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (!*philo->dead && !*philo->esc_eat)
		print_message(philo, 1);
	pthread_mutex_unlock(philo->dead_mutex);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (!*philo->dead && !*philo->esc_eat)
		print_message(philo, 2);
	pthread_mutex_unlock(philo->dead_mutex);
	ft_sleep(philo->input[T_EAT]);
	pthread_mutex_lock(philo->eat_mutex);
	philo->eat_num++;
	if (philo->input[M_EAT] != -1)
	{
		if (philo->eat_num >= philo->input[M_EAT])
			philo->eat_flag = 1;
		else
			philo->eat_flag = 0;
	}
	else if (philo->input[M_EAT] == -1)
		philo->eat_flag = 0;
	philo->last_eat = get_time();
	pthread_mutex_unlock(philo->eat_mutex);
}

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (!*philo->dead && !*philo->esc_eat)
		print_message(philo, 3);
	pthread_mutex_unlock(philo->dead_mutex);
	ft_sleep(philo->input[T_SLEEP]);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (!*philo->dead && !*philo->esc_eat)
		print_message(philo, 4);
	pthread_mutex_unlock(philo->dead_mutex);
}
