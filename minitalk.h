/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:49 by tmiftah           #+#    #+#             */
/*   Updated: 2023/02/14 18:59:35 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>

void	handler(int signal, siginfo_t *d, void *con);
int		ft_power(int nb, int power);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
#endif
