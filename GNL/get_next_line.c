/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:02:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/05 11:15:02 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	int 		i;
	int 		j;
	char		*ovr;
	char		buf[BUFF_SIZE + 1];
	char		*hold;
	int			in;
	static ins	*node;
	static vec	*v;

	if (node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if ( 
	hold = (char*)ft_memmalloc((BUFF_SIZE * 2) * sizeof(char));
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		{
			ovr = ft_linesplit((const char *)buf);
		}	
			return 
		if ()
			jasHGDKHJGFJKHGFHG
			return;
	}
	if (!line)
		return (-1);
}

static size_t	ft_countline(char const *s)
{
	size_t		l;
	size_t		i;
	char		c;

	w = 0;
	i = 0;
	c = '\n'
	if (!s)
		return (0);
	if (s[i] != c)
		l++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c) //&& s[i - 1] != '\0')
			l++;
		i++;
	}
	return (w);
}

char			**ft_linesplit(char const *s)
{
	size_t		w;
	char		**ar;

	if (!s)
		return (NULL);
	w = ft_countline(s);
	ar = (char **)ft_memalloc(sizeof(char *) * (w + 1));
	ft_strarr(s, ar, '\n', w);
	if (!ar)
		return (NULL);
	return (ar);
}


