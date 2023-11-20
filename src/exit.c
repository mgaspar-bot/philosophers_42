/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:51 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/20 20:26:55 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_exit(t_state *state)
{
	int	i;

	i = -1;
	while (++i < state->n_philos)
	{
		pthread_mutex_destroy(&state->forks[i]);
		pthread_detach(state->philos[i].thread);
	}
	free(state->forks);
	free(state->philos);
	//pthread_mutex_unlock(&state->sync_out);
	pthread_mutex_destroy(&state->sync_out);
}
/**
	After successful state init, we should have two arrays:
	one with n mutexes and one with n forks
	so cleaning up should mean cleaning the mutexes and then
	freeing the arrays
**/
