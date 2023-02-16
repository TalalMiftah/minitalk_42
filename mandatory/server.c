/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:28:08 by tmiftah           #+#    #+#             */
/*   Updated: 2023/02/14 19:16:18 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0 && n >= -2147483647)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
}

int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

void	handler(int signal, siginfo_t *d, void *con)
{
	static int	i;
	static int	pd;
	static int	j;
	char		c;

	con = NULL;
	if (pd != d->si_pid)
	{
		if (pd != 0)
			kill(pd, SIGTERM);
		pd = d->si_pid;
		i = 0;
		j = 0;
	}
	if (signal == SIGUSR1)
		j += ft_power(2, 7 - i);
	i++;
	if (i == 8)
	{
		c = j;
		write(1, &c, 1);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	int					pd;
	struct sigaction	mt;

	pd = getpid();
	// printf("%d\n", getuid());
	mt.sa_sigaction = &handler;
	mt.sa_flags = SA_SIGINFO;
	write (1, "PID : ", 6);
	ft_putnbr(pd);
	write (1, "\n", 1);
	sigaction(SIGUSR1, &mt, NULL);
	sigaction(SIGUSR2, &mt, NULL);
	while (1)
		pause();
	return (0);
}
