/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:34:48 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/23 23:23:33 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_countstr(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	st_wrdlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	st_split_recur(char **rtab, char *s, char c)
{
	int		wrdlen;
	int		endcode;

	while (*s && *s == c)
		s++;
	wrdlen = st_wrdlen(s, c);
	if (wrdlen == 0)
	{
		rtab[0] = NULL;
		return (1);
	}
	if (!(rtab[0] = malloc(sizeof(char) * (wrdlen + 1))))
		return (0);
	ft_strlcpy(rtab[0], s, wrdlen + 1);
	endcode = st_split_recur(rtab + 1, s + wrdlen, c);
	if (endcode == 0)
		free(rtab[0]);
	return (endcode);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		endcode;

	if (s == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char *) * (st_countstr(s, c) + 1))))
		return (NULL);
	endcode = st_split_recur(res, (char *)s, c);
	if (endcode == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
