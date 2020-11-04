/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokobaya <kokobaya@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:18:08 by kokobaya          #+#    #+#             */
/*   Updated: 2020/10/19 00:25:38 by kokobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	next = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = next;
	ft_lstclear(lst, del);
}
