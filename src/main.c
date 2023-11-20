/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:02:47 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/20 20:32:04 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	deathcheck(t_state *state)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < state->n_philos)
		{
			if (get_running_time(state) - state->philos[i].last_meal
				> (u_int64_t)state->t_die)
			{
				state->is_anyone_dead = 1;
				write_final_message(i, state);
				ft_exit(state);
				break ;
			}
			i++;
		}
		if (state->is_anyone_dead)
			break ;
	}
}

void	write_usage(void)
{
	ft_putstr_fd("\nUsage: ./philo n_philos t_die ", 1);
	ft_putstr_fd("t_eat t_sleep ", 1);
	ft_putstr_fd("[max_meals]\n\n", 1);
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
	start_dinner(&state);
	deathcheck(&state);
	return (SUCCESS);
}
