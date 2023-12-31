/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:04:05 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 22:28:21 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (SYSCALL_FAILED);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

u_int64_t	get_running_time(t_state *state)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (SYSCALL_FAILED);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000)
		- state->t_start);
}

void	ft_sleep(u_int64_t t_sleep)
{
	u_int64_t	start;

	start = get_time();
	while (get_time() - start < t_sleep)
		usleep(t_sleep / 10);
}
