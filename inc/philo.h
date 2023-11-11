/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:56:52 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/11 23:10:58 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0
# define BAD_ARGS -1
# define SYSCALL_FAILED -2

typedef struct s_state t_state;

typedef struct s_philo {
	pthread_t	thread;
	int			fork1;
	int			fork2;
	t_state		*state;
}	t_philo;

typedef struct s_state {
	int				t_die;
	int				t_eat;
	int				t_sleep;
	u_int64_t		t_start;
	t_philo			*philos;
	int				n_philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t sync_out;
	pthread_mutex_t sync_die;
	int				max_meals;
}	t_state;

int		init_state(int argc, char **argv, t_state *state);
int		start_dinner(t_state *state);
void	write_sync(char *str, pthread_mutex_t *sync_out);

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

#endif
