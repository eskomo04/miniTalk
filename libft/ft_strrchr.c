/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:38:50 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/18 00:38:50 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*last_occurrence;
	size_t		i;
	char		*sr;

	sr = (char *)s;
	last_occurrence = NULL;
	i = 0;
	while (sr[i] != '\0')
	{
		if (sr[i] == (char)c)
		{
			last_occurrence = &sr[i];
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (&sr[i]);
	}
	return (last_occurrence);
}
