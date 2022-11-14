/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:01:58 by pjang             #+#    #+#             */
/*   Updated: 2022/11/14 09:10:28 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define HEADS 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define M_EAT 4

typedef struct s_philo
{
	u_int64_t		start;
	u_int64_t		last_eat;
	int				input[5];
	int				p_num;
	int				eat_num;
	int				eat_flag;
	int				*esc_eat;
	int				*dead;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_mutex;
}				t_philo;

typedef struct s_data
{
	int				number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				esc_eat;
	int				dead;
	t_philo			*philo;
	pthread_t		thread;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;

}				t_data;

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
int			put_error(char	*err_msg);
void		print_message(t_philo *philo, int n);
u_int64_t	get_time(void);
void		ft_sleep(u_int64_t time);

// philo status
void		taken_a_fork(t_philo *philo);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
int			check(t_data *data, int n);

int			init(t_data *data);
void		parsing(t_data *data, int ac, char *av[]);
void		timestamp(t_philo *philo);
int			philo(t_data *data);

#endif