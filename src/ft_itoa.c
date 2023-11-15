/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:09:53 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/11/15 18:34:41 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	putstr(int n, char *str)
{
	int	magn;
	int	i;

	magn = 1;
	i = 0;
	while (n > magn)
	{
		magn *= 10;
		if (magn == 1000000000)
			break ;
	}
	if (n < magn)
		magn = magn / 10;
	while (magn)
	{
		str[i] = (n / magn) + 48;
		n = n % magn;
		magn = magn / 10;
		i++;
	}
}

int	xifres(int n)
{
	int	magn;
	int	xifres;

	magn = 1;
	xifres = 1;
	if (n >= 1000000000)
		return (10);
	while (n > magn)
	{
		magn *= 10;
		xifres++;
	}
	if (n < magn)
		xifres--;
	return (xifres);
}

int	calculate_sign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = calculate_sign(n);
	if (n < 0)
		n = -n;
	if (sign)
	{
		str = (char *)malloc((xifres(n) + 2) * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
		str = (char *)malloc((xifres(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[xifres(n) + sign] = 0;
	putstr(n, str + sign);
	return (str);
}
