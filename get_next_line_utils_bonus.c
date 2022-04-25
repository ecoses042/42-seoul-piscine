/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:25:08 by msong             #+#    #+#             */
/*   Updated: 2022/04/25 16:15:40 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	ssize_t	i;

	i = gnl_strchr(s1, '\0') + gnl_strchr(s2, '\0') + 1;
	if (!s2)
		return (0);
	result = (char *)malloc(i);
	if (!result)
		return (0);
	i = 0;
	while (i < gnl_strchr(s1, '\0'))
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < gnl_strchr(s2, '\0'))
	{
		result[i + gnl_strchr(s1, '\0')] = s2[i];
		i++;
	}
	result[i + gnl_strchr(s1, '\0')] = '\0';
	free(s1);
	return (result);
}

char	*gnl_cut(char *s, ssize_t i)
{
	char	*result;
	ssize_t	i2;
	ssize_t	len;

	len = gnl_strchr(s, '\0') - i;
	if (len < 1)
		return (0);
	i2 = 0;
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i2 <= len)
	{
		result[i2] = s[i + i2];
		i2++;
	}
	return (result);
}

t_list	*gnl_lstlast(t_list *lst)
{
	t_list	*a;

	if (!lst)
		return (0);
	a = lst;
	while (lst->next)
	{
		lst = lst->next;
		a = lst;
	}
	return (a);
}

void	gnl_lstadd_back(t_list **head, t_list *new)
{
	if (!new || !head)
		return ;
	if (!*head)
	{
		new->prev = *head;
		new->next = *head;
		*head = new;
		return ;
	}
	gnl_lstlast(*head)->next = new;
}

void	gnl_freenode(t_list **node)
{
	free((*node)->content);
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
	{
		(*node)->next->prev = (*node)->prev;
	}
	free(*node);
	*node = NULL;
}
