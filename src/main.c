/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/03 18:41:23 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data)

{
	int i;

	i = 0;
	data->simulation_start_time = get_time_ms() + 100;

	while (i < data->total_philosophers)
	{
		pthread_create(&data->philosophers[i].thread, NULL, philo_routine,
			&data->philosophers[i]);
		i++;
	}
	pthread_create(&data->monitor_thread, NULL, monitor_routine, data);
	i = 0;

	while (i < data->total_philosophers)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
		return (1);
	}
	pthread_join(data->monitor_thread, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data *data;
	data = NULL;

	if (ac != 5 && ac != 6)
		return (printf("Usage: ./philo nb_philo t_die t_eat t_sleep [must_eat]\n"),
			1);

	if (!correct_argv(ac, av))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data = init_data(ac, av);
	if (!data)
		return (1);

	return (0);
}