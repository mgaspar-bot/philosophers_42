/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:50:30 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/11 23:36:06 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	routine(t_philo *philo)
{
	write_sync(ft_itoa(philo->fork2), &philo->state->sync_out);
}

int	start_dinner(t_state *state)
{
	int	i;


	i = 0;
	state->t_start = get_time();
	//write_sync(ft_itoa(state->n_philos), &state->sync_out);
	while(i <= state->n_philos)
	{
		//ft_putstr_fd("Inside the loop\n", 1);
		pthread_create(&state->philos[i].thread, NULL, routine, &state->philos[i]);
		i++;
	}

	return (SUCCESS);
}