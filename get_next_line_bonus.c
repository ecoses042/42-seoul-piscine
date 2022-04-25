/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:22:13 by msong             #+#    #+#             */
/*   Updated: 2022/04/25 16:25:20 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	head;
	char			*result;
	t_list			*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	temp = gnl_get_fd(&head, fd);
	if (!temp)
		return (0);
	if (temp->content)
	{
		if (gnl_strchr(temp->content, '\n') != -1)
			return (gnl_get_line(temp));
		else
			gnl_start(fd, temp);
	}
	else
		gnl_start(fd, temp);
	if (!temp->content)
	{
		gnl_freenode(&temp);
		return (0);
	}
	result = gnl_get_line(temp);
	return (result);
}

int	gnl_start(int fd, t_list *head)
{
	ssize_t	len;
	char	*temp;

	len = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	while (gnl_strchr(head->content, '\n') == -1)
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len < 1)
			break ;
		temp [len] = '\0';
		head->content = gnl_strjoin(head->content, temp);
		if (!head->content)
			break ;
	}
	free(temp);
	if (!head->content)
		return (0);
	return (1);
}

char	*gnl_get_line(t_list *head)
{
	char	*line;
	ssize_t	i;
	ssize_t	i2;
	char	*temp;

	i2 = 0;
	i = gnl_strchr(head->content, '\n') + 1;
	if (i == 0)
		i = gnl_strchr(head->content, '\0');
	line = (char *)malloc(i + 1);
	if (!line)
	{
		free(head->content);
		return (0);
	}
	temp = head->content;
	while (i2 < i)
	{
		line[i2] = head->content[i2];
		i2++;
	}
	line[i2] = '\0';
	head->content = gnl_cut(temp, i);
	free(temp);
	return (line);
}

ssize_t	gnl_strchr(char	*str, int c)
{
	ssize_t	i;

	i = 0;
	if (!str && c != '\0')
		return (-1);
	if (!str && c == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}

t_list	*gnl_get_fd(t_list *head, int fd)
{
	t_list	*temp;

	temp = head->next;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		else
			temp = temp->next;
	}
	temp = malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->fd = fd;
	temp->next = NULL;
	temp->content = NULL;
	temp->prev = gnl_lstlast(head);
	gnl_lstadd_back(&head, temp);
	return (temp);
}
