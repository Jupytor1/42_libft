/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:33:56 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/19 00:27:00 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*next;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	if (lst->next == NULL)
		return (res);
	next = ft_lstmap(lst->next, f, del);
	if (next == NULL)
	{
		ft_lstdelone(res, del);
		return (NULL);
	}
	res->next = next;
	return (res);
}
