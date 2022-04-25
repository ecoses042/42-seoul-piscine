/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:26:17 by msong             #+#    #+#             */
/*   Updated: 2022/04/25 16:25:39 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct g_list{
	char			*content;
	struct g_list	*next;
	struct g_list	*prev;
	int				fd;
}t_list;

char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_cut(char *s, ssize_t i);
t_list	*gnl_lstlast(t_list *lst);
void	gnl_lstadd_back(t_list **head, t_list *new);
void	gnl_freenode(t_list **node);

char	*get_next_line(int fd);
int		gnl_start(int fd, t_list *head);
char	*gnl_get_line(t_list *head);
ssize_t	gnl_strchr(char *str, int c);
t_list	*gnl_get_fd(t_list	*head, int fd);
#endif
