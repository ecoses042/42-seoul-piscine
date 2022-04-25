/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:25:08 by msong             #+#    #+#             */
/*   Updated: 2022/04/25 13:58:45 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char const *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;

	i = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	if (!s2)
		return (0);
	result = (char *)malloc(i);
	if (!result)
		return (0);
	i = 0;
	while (i < gnl_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < gnl_strlen(s2))
	{
		result[i + gnl_strlen(s1)] = s2[i];
		i++;
	}
	result[i + gnl_strlen(s1)] = '\0';
	free(s1);
	return (result);
}

char	*gnl_cut(char *s, ssize_t i)
{
	char	*result;
	ssize_t	i2;
	ssize_t	len;

	len = gnl_strlen(s) - i;
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
