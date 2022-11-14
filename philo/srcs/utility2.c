/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:19:22 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:43:05 by pjang            ###   ########.fr       */
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
	time_t	time;

	time = (get_time() - philo->start) / 1000;
	put_time(time);
	write(1, " ms ", 4);
}

void	print_message(t_philo *philo, int n)
{
	pthread_mutex_lock(philo->print_mutex);
	timestamp(philo);
	put_time(philo->p_num);
	if (n == 1)
		ft_putstr_fd(" has taken a fork\n", 1);
	if (n == 2)
		ft_putstr_fd(" is eating\n", 1);
	if (n == 3)
		ft_putstr_fd(" is sleeping\n", 1);
	if (n == 4)
		ft_putstr_fd(" is thinking\n", 1);
	if (n == 5)
		ft_putstr_fd(" died\n", 1);
	pthread_mutex_unlock(philo->print_mutex);
}

u_int64_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000000 + now.tv_usec);
}
