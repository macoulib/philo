/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:47 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/04 14:26:19 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->shared_data;

	
	pthread_mutex_lock(&data->fork_mutexes[philo->fork[0]]);
	write_status(data, "has taken a fork");

	philo_sleep(data, data->time_to_die);

	pthread_mutex_unlock(&data->fork_mutexes[philo->fork[0]]);
	return (NULL);
}


void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->shared_data;
	start_delay(data->simulation_start_time);
	if (data->total_philosophers == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		philo_sleep(data, 1);
	while (!simulation_stopped(data))
	{
		pthread_mutex_lock(&data->fork_mutexes[philo->fork[0]]);
		write_status(data, "has taken a fork");
		pthread_mutex_lock(&data->fork_mutexes[philo->fork[1]]);
		write_status(data, "has taken a fork2");
		write_status(data, "is eating");
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->last_meal_time = get_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_time_lock);
		philo_sleep(data, data->time_to_eat);
		pthread_mutex_unlock(&data->fork_mutexes[philo->fork[0]]);
		pthread_mutex_unlock(&data->fork_mutexes[philo->fork[1]]);
		write_status(data, "is sleeping");
		philo_sleep(data, data->time_to_sleep);
		write_status(data, "is thinking");
		philo_sleep(data, 50);
	}
	return (NULL);
}
