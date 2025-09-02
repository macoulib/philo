/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/02 12:16:59 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data)
{
	unsigned	i;

	i = 0;
	data->start_time = get_time_ms() + (data->number_of_philosophers * 20);
	while (i < data->number_of_philosophers)
	{
		if (!pthread_create(&data->philos[i], NULL, &philosopher,
				&data->philos[i]))
			return (NULL);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data *data;
	data = NULL;

	if (ac != 5 && ac != 6)
	{
		write(2, "Utilisation : ./philo nb_philos temps_mort temps_repas ", 56);
		write(2, "temps_sommeil [nb_repas_requis]\n", 34);
		return (1);
	}

	if (!correct_argv(ac, av))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data = init_data(ac, av);

	return (0);
}