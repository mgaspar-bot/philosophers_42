/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:50:33 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 22:32:14 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_state *state, t_philo *philo)
{
	pthread_mutex_lock(&state->forks[philo->fork1]);
	write_message(SC_FORK_TAKEN, philo->fork2, state);
	pthread_mutex_lock(&state->forks[philo->fork2]);
	write_message(SC_FORK_TAKEN, philo->fork2, state);
}

void	eat(t_philo *philo)
{
	t_state		*state;
	u_int64_t	start;

	state = philo->state;
	start = state->t_start;
	take_forks(state, philo);
	philo->last_meal = get_running_time(state);
	write_message(SC_EATING, philo->fork2, state);
	ft_sleep(state->t_eat);
	pthread_mutex_unlock(&state->forks[philo->fork1]);
	pthread_mutex_unlock(&state->forks[philo->fork2]);
}
