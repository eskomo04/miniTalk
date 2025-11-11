/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 02:56:41 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/25 01:57:08 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_app;
	int		i;
	int		s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	str_app = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str_app)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str_app[i] = f(i, s[i]);
		i++;
	}
	str_app[i] = '\0';
	return (str_app);
}
