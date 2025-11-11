/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 05:09:57 by eskomo            #+#    #+#             */
/*   Updated: 2025/07/27 22:20:04 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_delimit(char c, char delimi)
{
	if (c == delimi)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static	int	ft_count_word(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_is_delimit(s[i], c) && (in_word == 0))
		{
			in_word = 1;
			count++;
		}
		else if (ft_is_delimit(s[i], c))
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static	void	*ft_free(char **splits, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	return (NULL);
}

static void	*ft_copy_words(char const *s, char c, int *adv)
{
	int		i;
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	*adv = len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**splits;
	int			i;
	int			adv;

	if (!s)
		return (NULL);
	splits = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!splits)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_is_delimit(*s, c))
			s++;
		if (*s)
		{
			splits[i] = ft_copy_words(s, c, &adv);
			if (!splits[i])
				return (ft_free(splits, i), NULL);
			s += adv;
			i++;
		}
	}
	splits[i] = NULL;
	return (splits);
}

// #include <stdio.h>

// int main(void)
// {
//     char    *str1 = "   word1   word2";
//     char    *str2 = "word1 word2";
//     char    *str3 = "   ";
//     char    *str4 = "";

//     char **result;
//     int i;

//     printf("Test string: \"%s\"\n", str1);
//     result = ft_split(str1, ' ');
//     if (!result)
//         return (1);
//     for (i = 0; result[i]; i++)
//         printf("[%s]\n", result[i]);
//     // free memory
//     for (i = 0; result[i]; i++)
//         free(result[i]);
//     free(result);

//     printf("\nTest string: \"%s\"\n", str2);
//     result = ft_split(str2, ' ');
//     for (i = 0; result[i]; i++)
//         printf("[%s]\n", result[i]);
//     for (i = 0; result[i]; i++)
//         free(result[i]);
//     free(result);

//     printf("\nTest string: \"%s\"\n", str3);
//     result = ft_split(str3, ' ');
//     if (result)
//     {
//         for (i = 0; result[i]; i++)
//             printf("[%s]\n", result[i]);
//         free(result);
//     }

//     printf("\nTest string: \"%s\"\n", str4);
//     result = ft_split(str4, ' ');
//     if (result)
//     {
//         for (i = 0; result[i]; i++)
//             printf("[%s]\n", result[i]);
//         free(result);
//     }
//     return (0);
// }