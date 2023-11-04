/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:02:47 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/04 20:09:46 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_usage(void)
{
	ft_putstr_fd("Usage: ./philo number_of_philosophers time_to_die ", 1);
	ft_putstr_fd("time_to_eat time_to_sleep ", 1);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]", 1);
}

int	validate_args(int argc, char **argv)
{
	int	found_error;

	(void)argv;
	found_error = 0;
	if (!(argc == 5 || argc == 6))
		found_error = 1;
	return (found_error);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (validate_args(argc, argv))
	{
		write_usage();
		return (BAD_ARGS);
	}
	if (init_state(argc, argv, &state))
		return (SYSCALL_FAILED);
	return (SUCCESS);
}
