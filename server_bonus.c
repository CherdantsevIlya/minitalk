/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:52:28 by pkari             #+#    #+#             */
/*   Updated: 2021/08/17 17:52:53 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n = n % 1000000000;
		n = n * (-1);
	}
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

static void	ft_unpacking(int signal, siginfo_t *siginfo, void *context)
{
	static int	byte;
	static int	i;
	static int	count;

	(void)context;
	if (count == 0)
		count = 128;
	if (signal == SIGUSR1)
		byte += count;
	count /= 2;
	i++;
	if (i == 8)
	{
		if (byte == 0)
		{
			kill(siginfo->si_pid, SIGUSR1);
			write (1, "\n", 1);
		}
		else
			write(1, &byte, 1);
		count = 128;
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("pid: \x1b[32m");
	ft_putnbr(getpid());
	ft_putstr("\x1b[0m\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_unpacking;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
