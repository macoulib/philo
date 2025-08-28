/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:12:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/08/28 15:08:05 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data *data;
	data = NULL;

	if (ac == 5 || ac == 6)
	{
		if (!correct_argv(ac, av))
			return (1);
        data = malloc(sizeof(t_data));
        if(!data)
            return (1);
		data = init_data(ac, av);
	}
	else
	{
		write(2, "Utilisation : ./philo nb_philos temps_mort temps_repas ", 56);
		write(2, "temps_sommeil [nb_repas_requis]\n", 34);
	}

	return (0);
}