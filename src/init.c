/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:38 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/02 17:54:06 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_data *data)
{
	if (data->philosophers->id % 2)
	{
		data->philosophers->fork[0] = (data->philosophers->id + 1)
			% data->total_philosophers;
		data->philosophers->fork[1] = data->philosophers->id;
	}
	data->philosophers->fork[0] = data->philosophers->id;
	data->philosophers->fork[1] = (data->philosophers->id + 1)
		% data->total_philosophers;
}

int	rest_and_mutexes_init(t_data *data)
{
	int				i;
	struct timeval	t;

	i = 0;
	gettimeofday(&t, NULL);
	data->philosopher_died = 0;
	data->required_meals = 0;
	data->simulation_start_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	if (!pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (!pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (0);
	if (!pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (0);
	while (++i < data->total_philosophers)
		if (!pthread_mutex_init(&data->fork_mutexes[i], NULL) != 0)
			return (0);
	return (1);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philosophers)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = data->simulation_start_time;
		data->philosophers[i].shared_data = data;
		take_fork(data);
		i++;
	}
	return (1);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->total_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->required_meals = ft_atoi(av[4]);
	else
		data->required_meals = -1;
	if (data->total_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| data->required_meals <= 0)
		return (NULL);
	data->fork_mutexes = malloc(sizeof(pthread_mutex_t)
			* data->total_philosophers);
	data->philosophers = malloc(sizeof(t_philo) * data->total_philosophers);
	if (!data->philosophers || !data->fork_mutexes)
		return (NULL);
	if (!rest_and_mutexes_init(data) || !init_philo(data))
		return (NULL);
	return (data);
}
