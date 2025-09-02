/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:40:33 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/02 18:54:44 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data)
{
	pthread_mutex_lock(&data->fork_mutexes[data->philosophers->fork[0]]);
	pthread_mutex_lock(&data->fork_mutexes[data->philosophers->fork[1]]);
	print_message(data, data->philosophers, "take fork ok");
	pthread_mutex_lock(&data->meal_mutex);
	print_message(data, data->philosophers, "is eating");
	data->philosophers->last_meal_time = get_time_ms();
	data->philosophers->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(&data->fork_mutexes[data->philosophers->fork[0]]);
	pthread_mutex_unlock(&data->fork_mutexes[data->philosophers->fork[1]]);
}