/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:58:50 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/23 23:18:26 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(res = malloc(size * count)))
		return (NULL);
	ft_bzero(res, count * size);
	return ((void *)res);
}
