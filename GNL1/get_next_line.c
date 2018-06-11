/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:45:48 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/11 14:30:18 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	chrcount(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	read_line(int fd, char *buf, ins *node)
{
	int		in;
	int		count;

	count = 0;
	if (chrcount(node->hold, '\n') ==  0)
	{	
		while ((in = read(fd, buf, BUFF_SIZE)) > 0)
		{
			count++;
			buf[in] = '\0';
			ft_strcat(node->hold, buf);
			if (ft_strchr(buf, '\n'))
				break ;
			ft_bzero(buf, BUFF_SIZE + 1);
		}
	}
	if (count > 0)
		return (1);
	else
		return (0);
}

static int			manage_line(ins *node, int fd, char *buf, char **line)
{
	int		in;
	char	*ptr;
	int		n;
	int		carryon;

	carryon = 0;
	ptr = NULL;
	n = 0;
	if (node->ovr != NULL)
	{
		ft_strcat(node->hold, node->ovr);
		ft_strclr(node->ovr);
	}
	in = read_line(fd, buf, node);
	if (ft_strchr(node->hold, '\n'))
	{
		ptr = ft_strchr(node->hold, '\n');
		*ptr = '\0';
		n++;
	}
	*line = ft_strdup(node->hold);
	if (node->hold[0] != '\0')
		carryon = 1;
	ft_strclr(node->hold);
	if (ptr)
		ft_strcat(node->ovr, ptr + 1);
	else
		ft_strcat(node->ovr, buf);
	if (in > 0 || n > 0 || carryon == 1)
		return (1);
	else 
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			in;
	char		buf[BUFF_SIZE + 1];
	static ins	*node;

	in = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 55000);
	if (!node->ovr)
		node->ovr = (char *)ft_memalloc(sizeof(char) * 55000);
	in = manage_line(node, fd, buf, line);
	if ((ft_strlen(*line) > 0))
		return (1);
	else
		return (0);
}
