/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:53:47 by pkari             #+#    #+#             */
/*   Updated: 2021/08/17 17:54:42 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	ft_atoi(const char *str)
{
	int			i;
	int			count;
	long int	nbr;

	i = 0;
	count = 1;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		count = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		if (nbr > 2147483647 && count == 1)
			return (-1);
		if (nbr > 2147483648 && count == -1)
			return (0);
		i++;
	}
	return (nbr * count);
}

static void	mess(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("\x1b[32mMessage successfully sent and printed\x1b[0m\n");
}

static int	ft_packing(pid_t pid, char c)
{
	int	byte;

	byte = 128;
	while (byte != 0)
	{
		if (c & byte)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		}
		byte /= 2;
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("\x1b[31mError: ./client [pid] [message]\x1b[0m\n");
		return (1);
	}
	signal(SIGUSR1, mess);
	pid = (pid_t)ft_atoi(argv[1]);
	while (argv[2][i])
	{
		if (ft_packing(pid, argv[2][i++]))
		{
			ft_putstr("\x1b[31mThe message wasn't delivered, check pid\x1b[0m\n");
			return (1);
		}
	}
	ft_packing(pid, '\0');
	return (0);
}
