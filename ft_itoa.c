/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:55:45 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/11 16:44:04 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_nbrlen(long n)
{
	if (n < 0)
		return (st_nbrlen(-n) + 1);
	if (n < 10)
		return (1);
	return (st_nbrlen(n / 10) + 1);
}

static int	st_ltoa(char *s, long n)
{
	int dig;

	if (n < 0)
	{
		s[0] = '-';
		dig = st_ltoa(s + 1, -n);
		return (dig + 1);
	}
	if (n < 10)
	{
		s[0] = '0' + n;
		return (1);
	}
	dig = st_ltoa(s, n / 10);
	s[dig] = '0' + n % 10;
	return (dig + 1);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		nbrlen;

	nbrlen = st_nbrlen(n);
	if (!(res = malloc(sizeof(char) * (nbrlen + 1))))
		return (NULL);
	st_ltoa(res, n);
	res[nbrlen] = '\0';
	return (res);
}
