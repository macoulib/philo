/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:32 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/02 12:19:07 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	**fork_locks;
	time_t			start_time;
	unsigned int	number_of_philosophers;
	pthread_t		grim_reaper;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				eat_count;
	bool			sim_stop;
	t_philo			**philos;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	food_time_lock;
	unsigned int	id;
	unsigned int	ates_time;
	time_t			last_meal;
	unsigned int	fork[2];
	t_data			*data;
}					t_philo;

int				correct_argv(int ac, char **av);
int					ft_atoi(char *str);
t_data				*init_data(int ac, char **av);
t_philo				**init_philo(t_data *data);
time_t				get_time_ms(void);
void				start_delay(time_t start);
void				*philosopher(void *x);
#endif