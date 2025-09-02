/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:38 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/01 16:22:01 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_all_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->fork_locks, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->sim_stop_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (0);
	return (1);
}

void	share_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->number_of_philosophers;
		philo->fork[1] = philo->id;
	}
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->data->number_of_philosophers;
}

t_philo	**init_philo(t_data *data)
{
	t_philo		**philos;
	unsigned	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!philos)
		return (NULL);
	while (i < data->number_of_philosophers)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (NULL);
		philos[i]->id = i;
		philos[i]->data = data;
		philos[i]->ates_time = 0;
		philos[i]->last_meal = 0;
		share_fork(philos[i]);
		i++;
	}
	return (philos);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->eat_count = ft_atoi(av[5]);
	else
		data->eat_count = -1;
	data->philos = init_philo(data);
	if (!data->philos)
		return (NULL);
	if (!init_all_mutex(data))
		return ;
	return (data);
}
