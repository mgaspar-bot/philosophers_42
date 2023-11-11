/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:51 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/11 23:34:45 by mgaspar-         ###   ########.fr       */
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
        //pthread_join(state->philos[i].thread);
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

void    write_sync(char *str, pthread_mutex_t *sync_out)
{
    pthread_mutex_lock(sync_out);
    //ft_putstr_fd("in write sync: ", 1);
    ft_putstr_fd(str, 1);
    //ft_putstr_fd("\n", 1);
    pthread_mutex_unlock(sync_out);
}