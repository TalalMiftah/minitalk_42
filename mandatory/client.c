/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:28:29 by tmiftah           #+#    #+#             */
/*   Updated: 2023/02/14 17:42:23 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += (*str - '0');
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		else if (result > 9223372036854775807)
			return (-1);
		str++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	int		j;
	char	c;

	j = 0;
	if (ac != 3)
		exit(1);
	pid = ft_atoi(av[1]);
	while (av[2][j])
	{
		i = 7;
		while (i >= 0)
		{
			c = av[2][j];
			if (1 & c >> i--)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(700);
		}
		usleep(700);
		j++;
	}
	return (0);
}
