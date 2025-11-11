/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 05:44:41 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/23 21:20:53 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	copy = malloc(len + 1);
	if (!copy)
	{
		return (NULL);
	}
	while (i <= len)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *original = "Hello world!";
//     char *copy = ft_strdup(original);

//     if (!copy)
//     {
//         printf("Allocation failed.\n");
//         return 1;
//     }

//     printf("Original: %s\n", original);
//     printf("Copy:     %s\n", copy);

//     free(copy);  // always free dynamically allocated memory
//     return 0;
// }