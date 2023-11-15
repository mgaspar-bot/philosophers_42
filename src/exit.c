/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:51 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 19:19:50 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    ft_exit(t_state *state)
{
    int i;

    i = -1;
    while (++i < state->n_philos)
    {
        pthread_mutex_destroy(&state->forks[i]);
        pthread_join(state->philos[i].thread, NULL);
    }
    free(state->forks);
    free(state->philos);
}
/**
    After successful state init, we should have two arrays:
    one with n mutexes and one with n forks
    so cleaning up should mean cleaning the mutexes and then
    freeing the arrays
**/
