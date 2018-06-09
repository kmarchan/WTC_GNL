/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:41:54 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/08 14:02:55 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	read_line(int fd, char **line)
{
//	int		in;
	char    buf[BUFF_SIZE + 1];
	static  ins *node;

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
	while ((node->in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[node->in] = '\0';
		ft_strcat(node->hold, buf);
		if  (ft_strchr(buf, '\n'))
		{
			break;
		}
		ft_bzero(buf, BUFF_SIZE);
	}
	if (node->in > 0)
		return (1);
	else
		return (0);
}