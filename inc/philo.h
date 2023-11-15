/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:56:52 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 20:22:57 by mgaspar-         ###   ########.fr       */
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
# define SC_FORK_TAKEN 0
# define SC_EATING 1
# define SC_SLEEPING 2
# define SC_THINKING 3
# define SC_DIED 4

typedef struct s_state	t_state;

typedef struct s_philo {
	pthread_t	thread;
	int			fork1;
	int			fork2;
	t_state		*state;
	u_int64_t	last_meal;
}	t_philo;

typedef struct s_state {
	int				t_die;
	int				t_eat;
	int				t_sleep;
	u_int64_t		t_start;
	t_philo			*philos;
	int				n_philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	sync_out;
	pthread_mutex_t	sync_die;
	int				max_meals;
}	t_state;

int			init_state(int argc, char **argv, t_state *state);
int			start_dinner(t_state *state);
void		write_message(u_int64_t now, int philo_index,
				int state_change, pthread_mutex_t *sync_out);
u_int64_t	get_time(void);
void		ft_sleep(u_int64_t t_sleep);
void		eat(t_philo *philo);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
