/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:05:14 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/14 23:32:02 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_numstart(const char *str)
{
	int i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || '9' < str[i]))
		return (-1);
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = st_numstart(str);
	if (i == -1)
		return (0);
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0') * sign;
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
		i++;
	}
	return ((int)res);
}
