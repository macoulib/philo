/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/02 18:53:28 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philosophers)
	{
		if (!pthread_create(&data->philosophers[i].thread, NULL, &philo_routine,
				&data->philosophers[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data *data;
	data = NULL;

	if (ac != 5 || ac != 6)
	{
		write(2, "Utilisation : ./philo nb_philos temps_mort temps_repas ", 56);
		write(2, "temps_sommeil [nb_repas_requis]\n", 34);
		return (1);
	}

	// if (!correct_argv(ac, av))
	// return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data = init_data(ac, av);
	if (!data)
		return (1);

	return (0);
}