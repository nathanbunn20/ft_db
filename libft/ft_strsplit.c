/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:37:25 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/24 11:51:36 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_word_count(char const *str, char c)
{
	int word_count;
	int i;
	int j;

	i = 0;
	j = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == c) && (str[i] != '\0'))
			i++;
		while ((str[i] != c) && (str[i] != '\0'))
		{
			i++;
			j++;
		}
		while ((str[i] == c) && (str[i] != '\0'))
			i++;
		if (j != 0)
		{
			word_count++;
			j = 0;
		}
	}
	return (word_count);
}

static int	ft_word_size(char const *str, char c)
{
	int i;
	int word_size;

	i = 0;
	word_size = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == c) && str[i] != '\0')
			i++;
		while ((str[i] != c) && str[i] != '\0')
		{
			i++;
			word_size++;
		}
		if (str[i] == c)
			return (word_size);
	}
	return (word_size);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**words;
	char	*word;
	int		words_entered;
	int		i;

	i = 0;
	words_entered = 0;
	if (!str)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * ft_word_count(str, c) + 1)))
		return (NULL);
	while (words_entered < (ft_word_count(str, c) + words_entered))
	{
		if (!(word = (char*)malloc(sizeof(char) * ft_word_size(str, c) + 1)))
			return (NULL);
		while (*str == c && *str != '\0')
			str++;
		while ((*str != c) && *str != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[words_entered] = 0;
	return (words);
}
