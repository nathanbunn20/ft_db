/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:28:24 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/07 16:37:39 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define SPACE(x) x == ' ' || x == '\n' || x == '\t'

static int	ft_word_count(char *str)
{
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (SPACE(str[i]) && str[i] != '\0')
			i++;
		while (!(SPACE(str[i])) && str[i] != '\0')
			i++;
		while (SPACE(str[i]) && str[i] != '\0')
			i++;
		word_count++;
	}
	return (word_count);
}

static int	ft_word_size(char *str)
{
	int i;
	int word_size;

	i = 0;
	word_size = 0;
	while (str[i] != '\0')
	{
		while (SPACE(str[i]) && str[i] != '\0')
			i++;
		while (!(SPACE(str[i])) && str[i] != '\0')
		{
			i++;
			word_size++;
		}
	}
	return (word_size);
}

char		**ft_splitwhitespaces(char *str)
{
	char	**words;
	char	*word;
	int		word_count;
	int		words_entered;
	int		i;

	i = 0;
	words_entered = 0;
	word_count = ft_word_count(str);
	words = (char**)malloc(sizeof(char*) * word_count + 1);
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * ft_word_size(str) + 1);
		while (SPACE(str[0]) && str[0] != '\0')
			str++;
		while (!(SPACE(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		words[words_entered++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}
