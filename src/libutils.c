/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:10:46 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 21:55:45 by mgaspar-         ###   ########.fr       */
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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nova;
	int		talla;
	int		i;

	talla = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	nova = (char *)malloc(talla * sizeof(char));
	if (!nova)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		nova[i] = s1[i];
		i++;
	}
	while (i < talla - 1)
	{
		nova[i] = *s2;
		i++;
		s2++;
	}
	nova[i] = 0;
	return (nova);
}
