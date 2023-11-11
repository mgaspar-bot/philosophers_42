/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:10:46 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/11 23:14:05 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		num = num * 10;
		num = num + (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
