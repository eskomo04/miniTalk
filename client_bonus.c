/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:54:42 by eskomo            #+#    #+#             */
/*   Updated: 2025/11/17 21:09:55 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniTalk_bonus.h"

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Acknowledgment received from server\n", 37);
	else
		write(1, "Acknowledgment received from server\n", 37);
}

void	ft_send_signal(pid_t pid, char c, int delay)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> (7 - bit)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(delay);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;
	int 	dellay;

	if (argc != 3)
	{
		write(1, "Must: ./client [PID] [STRING]\n", 32);
		return (1);
	}
	if (ft_strlen(argv[2]) > 10000)
		dellay = 600;
	else
		dellay = 300;
	server_pid = (pid_t)ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		signal(SIGUSR1, ack_handler);
		signal(SIGUSR2, ack_handler);
		ft_send_signal(server_pid, argv[2][i], dellay);
		i++;
	}
	ft_send_signal(server_pid, '\n', dellay);
	return (0);
}

// #include <stdio.h> // For debugging (optional)
// #include <sys/time.h> // For measuring time (optional)

// int	main(int argc, char **argv)
// {
// 	pid_t	server_pid;
// 	int		i;
// 	long	duration; // For measuring time (optional)
// 	struct timeval start, end; // For measuring time (optional)
// 	if (argc != 3)
// 	{
// 		write(1, "Must: ./client [PID] [STRING]\n", 32);
// 		return (1);
// 	}
// 	server_pid = (pid_t)atoi(argv[1]);
// 	i = 0;
// 	gettimeofday(&start, NULL); // Start time measurement (optional)
// 	while (argv[2][i])
// 	{
// 		signal(SIGUSR1, ack_handler);
// 		signal(SIGUSR2, ack_handler);
// 		ft_send_signal(server_pid, argv[2][i]);
// 		i++;
// 	}
// 	ft_send_signal(server_pid, '\n');
// 	gettimeofday(&end, NULL); // End time measurement (optional)
// 	duration = (end.tv_sec - start.tv_sec) * 1000000 + 
//(end.tv_usec - start.tv_usec); // Duration in microseconds (optional)
// 	printf("Time taken: %ld microseconds\n"
//, duration); // Print duration (optional)
// 	return (0);
// }