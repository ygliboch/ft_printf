/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:38:40 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:58:25 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if ((newlst = (t_list *)malloc(sizeof(t_list) * 1)) != NULL)
	{
		if (content == NULL)
		{
			newlst->content = NULL;
			newlst->content_size = 0;
		}
		else
		{
			newlst->content = ft_strnew(ft_strlen((char *)content));
			if (newlst->content == NULL)
				return (NULL);
			ft_memmove(newlst->content, content, ft_strlen((char *)content));
			newlst->content_size = content_size;
		}
		newlst->next = NULL;
		return (newlst);
	}
	return (NULL);
}
