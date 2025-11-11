/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:14:18 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/23 23:36:15 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = 0;
	p = (const unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char data[] = "Hell, world!";
//     char *ptr = ft_memchr(data, 'o', strlen(data));

//     if (ptr != NULL) {
//         printf("Found 'o' at position: %ld\n", ptr - data);
//     } else {
//         printf("'o' not found\n");
//     }

//     return 0;
// }