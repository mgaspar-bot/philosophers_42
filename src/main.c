/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:02:47 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/21 20:26:55 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_usage(void)
{
	ft_putstr_fd("\nUsage: ./philo n_philos t_die ", 1);
	ft_putstr_fd("t_eat t_sleep ", 1);
	ft_putstr_fd("[max_meals]\n\n", 1);
}

int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (!(argc == 5 || argc == 6))
		return (1);
	i = 1;
	while (argv[i] && i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9')
				&& !(argv[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	i = init_state(argc, argv, &state);
	if (i)
		return (i);
	start_dinner(&state);
	loop_check(&state);
	return (SUCCESS);
}
