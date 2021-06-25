/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:54:55 by afrasch           #+#    #+#             */
/*   Updated: 2021/06/25 16:28:35 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	tf;
	int	words;

	tf = 0;
	words = 0;
	while (*s)
	{
		if (*s == c)
			tf = 0;
		else if (tf == 0)
		{
			words++;
			tf = 1;
		}
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		j;
	int		start;

	if (!s || !c)
		return (0);
	words = ft_word_count(s, c);
	if (!(arr = malloc(sizeof(char *) * (words + 1))))
		return (0);
	i = j = 0;
	while (j <= words)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_substr(s, start, i - start);
		i++;
		j++;
	}
	arr[j] = 0;
	return (arr);
}
