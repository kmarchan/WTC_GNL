/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:45:48 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/08 12:39:32 by kmarchan         ###   ########.fr       */
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
int	get_next_line(const int fd, char **line)
{
//	int		c = 0;
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
//		node->c = chrcount(buf, '\n');
//		node->c--;
//		printf("c %d\n", node->c);
		ft_strcat(node->hold, buf);
		if  (ft_strchr(buf, '\n'))
		{
			break;
		}
		ft_bzero(buf, BUFF_SIZE);
//		node->c++;
	}
	ptr = NULL;
//	node->c = chrcout(node->hold, '\n');
	if (ft_strchr(node->hold, '\n'))
	{	
		*(ptr = ft_strchr(node->hold, '\n')) = '\0';
	}
	*line = ft_strdup(node->hold);
	ft_strclr(node->hold);	
	if (ptr)
		ft_strcat(node->ovr, ptr + 1);
	else 
		ft_strcat(node->ovr, buf);
//	if (node->c)
//		return (1);
	if (in >= 0 && ft_strlen(*line) > 0)
	{
//		node->c--;
//		printf("%d\n", node->c);
		return (1);
	}
	else
	   return (0);	
}

/*
#include <time.h>
#include <stdio.h>
int    main()
{

     clock_t start, end;
     double time_spent;
     
     start = clock();
    int i;
    int fd = open("test.txt", O_RDONLY);
    char    **line;
    line = malloc(100000);
    *line = malloc(100000);
    i = 1;
    int count = 0;
    while (i > 0)
    {    
        count++;
        i = get_next_line(fd, line);
 printf("%d: Buff: {%d}  len: %zu [%s]\n",i ,BUFF_SIZE,ft_strlen(*line), *line);
    }
     end = clock();
    

    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
     printf("%f\n",time_spent); 
    return(0);
}*/
