/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:02:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/06 12:38:13 by kmarchan         ###   ########.fr       */
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


int		get_next_line(const int fd, char **line)
{
	size_t	in;
	int l;
	int r;
	char *ptr;
//	char *hold;
	char buf[BUFF_SIZE + 1];
	static ins	*node;

	l = 0;
	r = 0;
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 1000);
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		r = read_next_buf(in);
		printf("%d, %s\n", r,  buf);
		
//	while (r > 0)
//	{
	//	if (r = 1)
	//	{
	//	while (buf)
	//	{
			if ((ptr = (ft_memchr(buf, '\n', BUFF_SIZE))))
			{
				printf("%s", ptr);
				*ptr = '\0';
				ft_strcpy(*line, buf);
				l++;
				ft_strclr(buf);
				*buf = *ptr + 1;
			}
		//	else
		//	{
			printf("%zu\t, l [%s]\n", in, *line);
			printf("%zu\t, p [%c]\n", in, *ptr);
			ft_strcat(node->hold, buf);
			ft_strclr(buf);
			printf("%zu\t, h [%s]\n", in,  node->hold);
		//	}
	//	}
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
