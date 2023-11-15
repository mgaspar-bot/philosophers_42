/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:50:30 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 20:30:54 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)ptr;
	state = philo->state;
	if (philo->fork2 % 2 != 0)
		ft_sleep(state->t_eat / 10);
	while (1)
	{
		eat(philo);
		ft_sleep(state->t_sleep);
	}
	// haurien de
	// pillar forquilles si son parells
	// actualitzar el seu last_meal && ft_sleep(t_eat);
	// alliberar forquilles
	// ft_sleep(t_sleep);
	// write_sync("im thinking...")
	// tornem a començar
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
	while(0 <= i)
	{
		pthread_join(state->philos[i].thread, NULL);
		i--;
	}

	return (SUCCESS);
}
