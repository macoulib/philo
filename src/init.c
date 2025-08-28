/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:38 by macoulib          #+#    #+#             */
/*   Updated: 2025/08/28 15:08:19 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
        philos[i]->ates_time =  0;
        philos[i]->last_meal = 0;
	}
    return (philos);
}

t_data	*init_data(int ac, char **av)
{
	t_data *data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->eat_count = ft_atoi(av[5]);
	data->eat_count = -1;
    data->philos = init_philo(data);
    
    return (data);
}