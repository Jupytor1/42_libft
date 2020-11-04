/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:35:12 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/23 23:39:13 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_strlcpy(res, s1, s1len + 1);
	ft_strlcpy(res + s1len, s2, s2len + 1);
	return (res);
}
