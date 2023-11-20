/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:02:47 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/20 21:29:28 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	fullcheck(t_state *state, int i)
{
	static int	full_philos = 0;

	if (!state->philos[i].full
		&& state->philos[i].meals_eaten == state->max_meals)
	{
		state->philos[i].full = 1;
		full_philos++;
		if (full_philos == state->n_philos)
		{
			state->is_anyone_dead = 1;
			write_message("Everyone full\n", i, state);
			return (1);
		}
	}
	return (0);
}

int	deathcheck(t_state *state, int i)
{
	if (get_running_time(state) - state->philos[i].last_meal
		> (u_int64_t)state->t_die)
	{
		state->is_anyone_dead = 1;
		write_final_message(i, state);
		return (1);
	}
	return (0);
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
	int		i;

	if (validate_args(argc, argv))
	{
		write_usage();
		return (BAD_ARGS);
	}
	if (init_state(argc, argv, &state))
		return (SYSCALL_FAILED);
	start_dinner(&state);
	while (1)
	{
		i = -1;
		while (++i < state.n_philos)
		{
			if (deathcheck(&state, i)
				|| (state.max_meals != -1 && fullcheck(&state, i)))
			{
				ft_exit(&state);
				break ;
			}
		}
		if (state.is_anyone_dead)
			break ;
	}
	return (SUCCESS);
}
