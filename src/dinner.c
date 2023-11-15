/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:50:30 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 23:05:54 by mgaspar-         ###   ########.fr       */
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
	if (philo->fork2 % 2 != 0)
		ft_sleep(state->t_eat / 10);
	while (!state->is_anyone_dead)
	{
		eat(philo);
		if (am_i_dead(philo, state))
			break ;
		write_message(SC_SLEEPING, philo->fork2, state);
		if (am_i_dead(philo, state))
			break ;
		ft_sleep(state->t_sleep);
		if (am_i_dead(philo, state))
			break ;
		write_message(SC_THINKING, philo->fork2, state);
		if (am_i_dead(philo, state))
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
	while (1)
	{
		i = 0;
		while (i < state->n_philos)
		{
			if (get_running_time(state) - state->philos[i].last_meal
				> (u_int64_t)state->t_die)
			{
				state->is_anyone_dead = 1;
				write_message(SC_DIED, i, state);
				break ;
			}
			i++;
		}
		if (state->is_anyone_dead)
			break ;
	}
	while(0 <= i)
	{
		pthread_join(state->philos[i].thread, NULL);
		i--;
	}

	return (SUCCESS);
}
