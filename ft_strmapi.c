/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:03:36 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/19 00:00:45 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	slen;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * (slen + 1))))
		return (NULL);
	i = 0;
	while (i < slen)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
