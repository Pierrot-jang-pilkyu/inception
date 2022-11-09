/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:43:47 by pjang             #+#    #+#             */
/*   Updated: 2022/11/09 19:11:54 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taken_a_fork(t_data *data, int i)
{
	char	c;

	timestamp(&data->philo[i]);
	c = data->p_num + '0';
	write(1, &c, 1);
	ft_putstr_fd(" has taken a fork\n", 1);
}

void	is_eating(t_data *data, int i)
{
	char	c;

	timestamp(&data->philo[i]);
	c = data->p_num + '0';
	write(1, &c, 1);
	ft_putstr_fd(" is eating\n", 1);
	usleep(data->time_to_eat * 1000);
}

int	is_sleeping(t_data *data, int i)
{
	char	c;

	if (check_dead(data, i))
	{
		data->dead = 1;
		return (1);
	}
	timestamp(&data->philo[i]);
	c = data->p_num + '0';
	write(1, &c, 1);
	ft_putstr_fd(" is sleeping\n", 1);
	usleep(data->time_to_sleep * 1000);
	return (0);
}

int	is_thinking(t_data *data, int i)
{
	char	c;

	if (check_dead(data, i))
	{
		data->dead = 1;
		return (1);
	}
	timestamp(&data->philo[i]);
	c = data->p_num + '0';
	write(1, &c, 1);
	ft_putstr_fd(" is thinking\n", 1);
	return (0);
}

int	check_dead(t_data *data, int i)
{
	char		c;
	suseconds_t	time;

	gettimeofday(&data->philo[i].now, NULL);
	time = (data->philo[i].now.tv_usec - data->philo[i].start.tv_usec) * 1000;
	if (time >= data->time_to_die)
	{
		timestamp(&data->philo[i]);
		c = data->p_num + '0';
		write(1, &c, 1);
		ft_putstr_fd(" died\n", 1);
		return (1);
	}
	return (0);
}
