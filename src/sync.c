/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:50:33 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/16 20:38:28 by mgaspar-         ###   ########.fr       */
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

	state = philo->state;
	take_forks(state, philo);
	philo->last_meal = get_running_time(state);
	write_message(SC_EATING, philo->fork2, state);
	ft_sleep(state->t_eat);
	pthread_mutex_unlock(&state->forks[philo->fork1]);
	pthread_mutex_unlock(&state->forks[philo->fork2]);
}

int	deathcheck(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (get_running_time(state) - philo->last_meal > (u_int64_t)state->t_die)
	{
		write_message(SC_DIED, philo->fork2, state);
		state->is_anyone_dead = 1;
		return (1);
	}
	if (state->is_anyone_dead)
		return (1);
	return (0);
}

int	state_change(char *state_change, t_philo *philo, pthread_mutex_t *mutex)
{
	if (deathcheck(philo))
		return (1);
	if (mutex)
		pthread_mutex_lock(mutex);
	write_message(state_change, philo->fork2, philo->state);
	return (0);
}

/**
 *
 * Vaig a intentar implementar un deathcheck ABANS de cada state
 * change. Un death change es posar-se a esperar un mutex.
 *
 * També posarem un deathcheck abans de escriure un missatge
 *
 * d'aquesta manera:
 * 	checkejo que no hagi mort ningu
 * 	espero el mutex
 * 	escric el missatge si no hi ha ningu mort
 * 	checkejo que no hagi mort ningu abans d'esperar el
 * 		seguent mutex
*/
