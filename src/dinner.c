/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:50:30 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/16 20:43:23 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	am_i_dead(t_philo *philo, t_state *state)
{
	if (get_running_time(state) - philo->last_meal
		> (u_int64_t)state->t_die)
	{
		write_final_message(philo->fork2, state);
		return (1);
	}
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)ptr;
	state = philo->state;
	philo->last_meal = 0;
	if (philo->fork2 % 2 != 0)
		ft_sleep(state->t_eat / 10);
	while (!state->is_anyone_dead)
	{
		if (state_change(SC_FORK_TAKEN, philo, &state->forks[philo->fork1]))
		{
			pthread_mutex_unlock(&state->forks[philo->fork1]);
			break ;
		}
		if (state_change(SC_FORK_TAKEN, philo, &state->forks[philo->fork2]))
		{
			pthread_mutex_unlock(&state->forks[philo->fork1]);
			pthread_mutex_unlock(&state->forks[philo->fork2]);
			break ;
		}
		philo->last_meal = get_running_time(state);
		if (state_change(SC_EATING, philo, NULL))
		{
			pthread_mutex_unlock(&state->forks[philo->fork1]);
			pthread_mutex_unlock(&state->forks[philo->fork2]);
			break ;
		}
		ft_sleep(state->t_sleep);
		pthread_mutex_unlock(&state->forks[philo->fork1]);
		pthread_mutex_unlock(&state->forks[philo->fork2]);
		if (state_change(SC_SLEEPING, philo, NULL))
			break ;
		ft_sleep(state->t_sleep);
		if (state_change(SC_THINKING, philo, NULL))
			break ;
	}
	return (NULL);
}

int	start_dinner(t_state *state)
{
	int	i;

	i = 0;
	state->t_start = get_time();
	while (i < state->n_philos)
	{
		pthread_create(&state->philos[i].thread, NULL, routine,
			&state->philos[i]);
		i++;
	}
	while (0 <= i)
	{
		pthread_join(state->philos[i].thread, NULL);
		i--;
	}
	return (SUCCESS);
}
