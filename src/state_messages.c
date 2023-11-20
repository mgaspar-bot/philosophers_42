/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:31:24 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/20 20:42:40 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_final_message(int philo_index, t_state *state)
{
	u_int64_t	now;

	now = get_running_time(state);
	pthread_mutex_lock(&state->sync_out);
	printf("%llu %d %s", now, philo_index, SC_DIED);
}

void	write_message(char *state_change, int philo_index, t_state *state)
{
	u_int64_t	now;

	now = get_running_time(state);
	pthread_mutex_lock(&state->sync_out);
	printf("%llu %d %s", now, philo_index, state_change);
	pthread_mutex_unlock(&state->sync_out);
}
