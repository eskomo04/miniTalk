/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:08:53 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/23 21:20:53 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_neg_check(int n)
{
	if (n < 0)
	{
		return (1);
	}
	return (0);
}

int	ft_digit_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	digit;
	int		len;
	int		neg;
	char	*itoa;

	digit = n;
	neg = ft_neg_check(n);
	len = ft_digit_len(n) + neg;
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (digit < 0)
		digit = -digit;
	if (digit == 0)
		itoa[--len] = '0';
	while (digit)
	{
		itoa[--len] = (digit % 10) + '0';
		digit /= 10;
	}
	if (neg)
		itoa[0] = '-';
	return (itoa);
}

// #include <stdio.h>

// int main(void)
// {
//     char *str;

//     str = ft_itoa(0);
//     printf("n = 0 → %s\n", str);
//     free(str);

//     str = ft_itoa(42);
//     printf("n = 42 → %s\n", str);
//     free(str);

//     str = ft_itoa(-42);
//     printf("n = -42 → %s\n", str);
//     free(str);

//     str = ft_itoa(2147483647);
//     printf("n = 2147483647 → %s\n", str);
//     free(str);

//     str = ft_itoa(-2147483648);
//     printf("n = -2147483648 → %s\n", str);
//     free(str);

//     return 0;
// }