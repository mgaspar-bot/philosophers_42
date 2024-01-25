/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:43:35 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/21 22:37:42 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	deathcheck(t_state *state, int i)
{
	long long unsigned	now;
	long long unsigned	meal;

	meal = state->philos[i].last_meal;
	now = get_running_time(state);
	// case meal > now is fucked up
	if (meal <= now && now - meal
		>= (u_int64_t)state->t_die)
	{
		state->is_anyone_dead = 1;
		write_final_message(i, state);
		return (1);
	}
	return (0);
}

void	loop_check(t_state *state)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < state->n_philos)
		{
			if ((state->n_philos == 1 || !state->philos[i].is_eating)
				&& deathcheck(state, i))
			{
				ft_exit(state);
				break ;
			}
		}
		if (state->is_anyone_dead)
			break ;
	}
}
