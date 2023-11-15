/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:31:24 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 20:42:09 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

char	*assemble_message(u_int64_t now, int philo_index, int state_change)
{
	char	*message;
	char	*now_str;
	char	*philo_index_str;
	char	*verb;

	now_str = ft_itoa(now);
	philo_index_str = ft_itoa(philo_index);
	if (state_change == SC_FORK_TAKEN)
		verb = ft_strdup(" has taken a fork\n");
	else if (state_change == SC_EATING)
		verb = ft_strdup(" is eating\n");
	else if (state_change == SC_SLEEPING)
		verb = ft_strdup(" is sleeping\n");
	else if (state_change == SC_THINKING)
		verb = ft_strdup(" is thinking\n");
	else if (state_change == SC_DIED)
		verb = ft_strdup(" died\n");
	write(1, "here\n", 5);
	message = ft_strjoin(now_str, ft_strdup(" "));
	message = ft_strjoin(message, philo_index_str);
	message = ft_strjoin(message, verb);
	return (message);
}
/**
 * Em trobo que em diu que el segon param del primer strjoin
 * intenta alliberar un punter que no ha estat allocated
 * pero strdup(" ") alloca la string que retorna...
 * llavors que esta passant?
 * */


void	write_message(u_int64_t now, int philo_index,
	int state_change, pthread_mutex_t *sync_out)
{
	char	*msg;

	msg = assemble_message(now, philo_index, state_change);
	pthread_mutex_lock(sync_out);
	ft_putstr_fd(msg, 1);
	pthread_mutex_unlock(sync_out);
	free(msg);
}
