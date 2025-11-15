/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:26:53 by eskomo            #+#    #+#             */
/*   Updated: 2025/11/15 04:22:44 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniTalk.h"

void	ft_send_signal(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> (7 - bit)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		write(1, "Must: ./client [PID] [STRING]\n", 32);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send_signal(server_pid, argv[2][i]);
		i++;
	}
	ft_send_signal(server_pid, '\n');
	return (0);
}

// #include <stdio.h> // For debugging (Not-Mandetory)
// #include <sys/time.h> // For measuring time (Not-Mandetory)

// int	main(int argc, char **argv)
// {
// 	pid_t	server_pid;
// 	int		i;
// 	struct timeval start, end; // For measuring time (Not-Mandetory)
// 	long duration;

// 	if (argc != 3)
// 	{
// 		write(1, "Must: ./client [PID] [STRING]\n", 32);
// 		return (1);
// 	}
// 	server_pid = (pid_t)atoi(argv[1]);
// 	i = 0;
// 	gettimeofday(&start, NULL); // Start time measurement (Not-Mandetory)
// 	while (argv[2][i])
// 	{
// 		ft_send_signal(server_pid, argv[2][i]);
// 		i++;
// 	}
// 	ft_send_signal(server_pid, '\n');
// 	gettimeofday(&end, NULL); // End time measurement (Not-Mandetorz)
// 	duration = (end.tv_sec - start.tv_sec) * 1000000 + 
//(end.tv_usec - start.tv_usec); // Duration in microseconds (Not-Mandetory)
// 	printf("Time taken: %ld microseconds\n", duration);
// 	return (0);
// }