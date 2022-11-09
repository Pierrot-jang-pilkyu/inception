/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:01:58 by pjang             #+#    #+#             */
/*   Updated: 2022/11/09 19:09:17 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct timeval	start;
	struct timeval	last_eat;
	struct timeval	now;
	int				eat_flag;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

typedef struct s_data
{
	int		number;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	int		p_num;
	int		dead;
	t_philo	*philo;
}				t_data;

void	ft_putstr_fd(char *str, int fd);
int		put_error(char	*err_msg);

// philo status
void	taken_a_fork(t_data *data, int i);
void	is_eating(t_data *data, int i);
int		is_sleeping(t_data *data, int i);
int		is_thinking(t_data *data, int i);
int		check_dead(t_data *data, int i);

int		init(t_data *data);
void	parsing(t_data *data, int ac, char *av);
void	timestamp(t_philo *philo);
int		philo(t_data *data);

#endif