/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:05:06 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/01 15:07:48 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_ms(void)
{
	struct timeval		x;

	gettimeofday(&x, NULL);
	return ((x.tv_sec * 1000) + (x.tv_usec / 1000));
}


void	start_delay(time_t start)
{
	while (get_time_ms() < start)
		continue ;
}