/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:45:48 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/08 14:39:03 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int		in;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	static	ins	*node;
	
	ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 55000);
	if (!node->ovr)
		node->ovr = (char *)ft_memalloc(sizeof(char) * 55000);			
	if (node->ovr != NULL)
	{
		ft_strcat(node->hold, node->ovr);
		ft_strclr(node->ovr);
	}
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[in] = '\0';
		ft_strcat(node->hold, buf);
		if  (ft_strchr(buf, '\n'))
			break;
		ft_bzero(buf, BUFF_SIZE);
	}
	ptr = NULL;
	if (ft_strchr(node->hold, '\n'))
		*(ptr = ft_strchr(node->hold, '\n')) = '\0';
	*line = ft_strdup(node->hold);
	ft_strclr(node->hold);	
	if (ptr)
		ft_strcat(node->ovr, ptr + 1);
	else 
		ft_strcat(node->ovr, buf);
	if (in >= 0 && ft_strlen(*line) > 0)
		return (1);
	else
		return (0);	
}
