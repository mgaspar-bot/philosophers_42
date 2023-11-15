/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:50:33 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 20:33:59 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->fork1]);
	write_message(get_time(), philo->fork2, SC_FORK_TAKEN,
		&philo->state->sync_out);
	pthread_mutex_lock(&philo->state->forks[philo->fork2]);
	write_message(get_time(), philo->fork2, SC_FORK_TAKEN,
		&philo->state->sync_out);
	philo->last_meal = get_time();
	write_message(get_time(), philo->fork2, SC_EATING,
		&philo->state->sync_out);
	ft_sleep(philo->state->t_eat);
}
