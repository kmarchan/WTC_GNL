/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:02:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/06 13:46:52 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	read_next_buf(size_t in)
{
	if (in > 0)
		return (1);
	return (0);
}

int	ft_srchrep(char *str, char s, char r)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str && s && r)
	{
		while (str[i] != '\0')
		{
			if (str[i] == s)
			{
				str[i] = r;
			}	
			i++;
		}
		count++;
	}		
	return (count);
}


int		get_next_line(const int fd, char **line)
{
	size_t	in;
	int l;
//	int i;
	int lc;
//	char *ptr;
	char buf[BUFF_SIZE + 1];
	static ins	*node;

	l = 0;
//	r = 0;
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 1000);
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
	//	r = read_next_buf(in);
	//	printf("before %s, ", buf);
	//	lc = ft_srchrep(buf, '\n', '\0');
//		i = 0;
	//	printf("after %s\n, ", buf);
		while (l <= lc)//i < BUFF_SIZE)
		{
			ptr = ft_memccpy(*line, buf, '\0', BUFF_SIZE);
			l++;
		}
		while (l--)
		{
			ft_strclr(buf);
		}
		/*	printf("%d, %s\n", r,  buf);
			printf("f");
			ptr = (ft_memchr(buf, '\n', BUFF_SIZE));
			printf("f");
			if ((*ptr) == '\n')
			{
				//(ptr - 1) = '\0';
				printf("f");
				printf("%s", buf);
				ft_memccpy(*line, buf, '\n', BUFF_SIZE);
				l++;
				ft_strclr(buf);
				*buf = *ptr + 1;*/
	//		printf("%s", buf);
	//		printf("%zu\t, l [%s]\n", in, *line);
	//	printf("%zu\t, p [%c]\n", in, *ptr);
			ft_strcat(node->hold, buf);
			ft_strclr(buf);
//			printf("%zu\t, h [%s]\n", in,  node->hold);
	}
	return (1);
}

/*
int main()
{
	int i;
	
    	// int fd = open("test.txt", O_RDONLY);
	
   	 // line = malloc(1000);
 	 // *line = malloc(1000);

   	 int fd2 = open("test2.txt", O_RDONLY);
   	 char     **line2;
   	 // char    **line;
   	 line2 = malloc(100000);
   	 *line2 = malloc(100000);
   	 // int id;

   	 i = get_next_line(fd2, line2);
  	 printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line2), *line2);	
}
*/

int	main()
{
	int fd = open("file.txt", O_RDONLY);
	int i;
	char **line;

	line = malloc(1000);
	*line = malloc(1000);	
	i = get_next_line(fd, line);
	printf("m%d\t, [%s]\n", i, *line);
	i = get_next_line(fd, line); 
	printf("m%d\t, [%s]\n", i, *line);
	i = get_next_line(fd, line);
	printf("m%d\t, [%s]\n", i, *line);
	return (0);
}
