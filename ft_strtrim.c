/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:56:49 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/18 23:17:22 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_memchr(set, s1[0], ft_strlen(set)) != NULL)
		return (ft_strtrim(s1 + 1, set));
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_memchr(set, s1[i], ft_strlen(set)) != NULL)
		i--;
	end = i;
	if (!(res = malloc(sizeof(char) * (end + 2))))
		return (NULL);
	ft_strlcpy(res, s1, end + 2);
	return (res);
}
