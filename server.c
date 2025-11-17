/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:45:30 by eskomo            #+#    #+#             */
/*   Updated: 2025/11/17 01:31:34 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniTalk.h"
/**
 * @signum: signal received (SIGUSR1 or SIGUSR2)
 * Description: This function converts the received bits into characters.
 * Each time a signal is received, it shifts the current character left by one
 * bit and adds the new bit (0 for SIGUSR1, 1 for SIGUSR2). When 8 bits have been
 * received, it writes the character to standard output and resets the character
 * and bit count.
 */
void	bit_to_char(int signum, siginfo_t *info, void *context)
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
		c = 0;
		bit = 0;
		kill(info->si_pid, SIGUSR1);
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
	write(1, "Server PID: ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = bit_to_char;
	act.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
