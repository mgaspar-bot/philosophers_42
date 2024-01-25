/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:50:30 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/21 22:34:39 by mgaspar-         ###   ########.fr       */
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

	philo->is_eating = 1;
	state = philo->state;
	start = state->t_start;
	take_forks(state, philo);
	philo->last_meal = get_running_time(state);
	philo->meals_eaten++;
	write_message(SC_EATING, philo->fork2, state);
	ft_sleep(state->t_eat);
	pthread_mutex_unlock(&state->forks[philo->fork1]);
	pthread_mutex_unlock(&state->forks[philo->fork2]);
	philo->is_eating = 0;
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)ptr;
	state = philo->state;
	if (philo->fork2 % 2 != 0)
		ft_sleep(state->t_eat / 10);
	while (!state->is_anyone_dead)
	{
		eat(philo);
		if (state->max_meals != -1 && philo->meals_eaten == state->max_meals)
			break ;
		write_message(SC_SLEEPING, philo->fork2, state);
		ft_sleep(state->t_sleep);
		write_message(SC_THINKING, philo->fork2, state);
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
	return (SUCCESS);
}
