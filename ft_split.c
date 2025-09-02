/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:20:07 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/02 15:28:09 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word( char const *s, char c)
{
	int	counter;
	int	flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

static char	*assign_word(char const *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[start] && start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_words(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	return (arr);
}

static int	main_while(char **arr, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = -1;
	start = -1;
	j = 0;
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == (int)ft_strlen(s)))
		{
			arr[j] = assign_word(s, start, i);
			if (!arr[j])
			{
				free_words(arr);
				free(arr);
				return (-1);
			}
			j++;
			start = -1;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	if (!s)
		return (NULL);
	arr = (char **) malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	j = main_while(arr, s, c);
	if (j == -1)
		return (NULL);
	arr[j] = 0;
	return (arr);
}
