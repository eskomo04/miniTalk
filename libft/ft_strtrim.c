/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:29:24 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/28 00:26:50 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_inset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimstr;
	size_t		start;
	size_t		end;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && ft_is_inset(s1[start], set))
		start++;
	while ((end > start) && (ft_is_inset(s1[end], set)))
	{
		end--;
	}
	len = end - start + 1;
	trimstr = (char *)malloc(sizeof (char) * (len + 1));
	if (!trimstr)
	{
		return (NULL);
	}
	ft_strlcpy(trimstr, s1 + start, len + 1);
	return (trimstr);
}
