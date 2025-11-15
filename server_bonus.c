/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:54:36 by eskomo            #+#    #+#             */
/*   Updated: 2025/11/06 03:00:08 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniTalk_bonus.h"

void	bit_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	if (signum == SIGUSR2)
		c = (c << 1) | 1;
	else if (signum == SIGUSR1)
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		kill(info->si_pid, SIGUSR1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	if (pid == -1)
	{
		write(1, "Error getting PID\n", 18);
		return (0);
	}
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = bit_handler;
	act.sa_flags = SA_RESTART | SA_SIGINFO;
	write(1, "Server PID: ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
