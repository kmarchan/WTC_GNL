/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:02:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/04 14:26:05 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	int 		i;
	int 		j;
	char		*ovr;
	char buf[BUFF_SIZE + 1];
	int in;
	
	*line = (char*)malloc((BUFF_SIZE *2) * sizeof(char));
	while (in = read(fd, buf, BUFF_SIZE) > 0)
	{
		while (*buf)
			if()
				akjudhfakjdhfkljdfh
					return 
		if ()
			jasHGDKHJGFJKHGFHG
			return;
	}
	if (!line)
		return (-1);
}
