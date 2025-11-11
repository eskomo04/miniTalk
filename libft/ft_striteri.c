/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 05:15:31 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/23 21:20:53 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	s_len;

	i = 0;
	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		(*f)(i, s + i);
		i++;
	}
}

// void to_upper(unsigned int i, char *c)
// {
//     (void)i; // we don’t need the index here
//     if (*c >= 'a' && *c <= 'z')
//         *c = *c - 32;
// }

// int main(void)
// {
//     char str[] = "hello world"; // must not be const, because we modify it

//     printf("Before: %s\n", str);
//     ft_striteri(str, to_upper);
//     printf("After:  %s\n", str);

//     return 0;
// }