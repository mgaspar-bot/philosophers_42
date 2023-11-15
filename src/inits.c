/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:51 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 22:38:02 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_forks(t_state *state)
{
	int	i;

	state->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (state->n_philos));
	if (state->forks == NULL)
		return (SYSCALL_FAILED);
	i = 0;
	while (i < state->n_philos)
		pthread_mutex_init(&state->forks[i++], NULL);
	//ft_putstr_fd("Got out of the second loop\n", 1);
	pthread_mutex_init(&state->sync_out, NULL);
	pthread_mutex_init(&state->sync_die, NULL);
	return (SUCCESS);
}
/**
	Philo with index 0 can take fork with index 0
	and with index n - 1
*/
int	init_philos(t_state *state)
{
	int	i;

	state->philos = (t_philo *)malloc(sizeof(t_philo) * (state->n_philos + 1));
	if (state->philos == NULL)
		return (SYSCALL_FAILED);
	i = 0;
	while (i < state->n_philos)
	{
		state->philos[i].fork1 = i - 1;
		state->philos[i].fork2 = i;
		if (i == 0)
			state->philos[i].fork1 = state->n_philos - 1;
		state->philos[i].state = state;
		i++;
	}
	return (SUCCESS);
}

int	init_state(int argc, char **argv, t_state *state)
{
	int	i;
	int	p;

	i = 0;
	while (++i < argc)
	{
		p = ft_atoi(argv[i]);
		if (i == 1)
			state->n_philos = p;
		if (i == 2)
			state->t_die = p;
		if (i == 3)
			state->t_eat = p;
		if (i == 4)
			state->t_sleep = p;
		if (i == 5)
			state->max_meals = p;
	}
	state->is_anyone_dead = 0;
	//ft_putstr_fd("Got out of the first loop\n", 1);
	if (init_forks(state))
		return (SYSCALL_FAILED);
	return (init_philos(state));
}
