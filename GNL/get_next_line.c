/*****gnl*******/
#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	int		in;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	static	ins	*node;
	
	ft_bzero(buf, BUFF_SIZE + 1);
//	printf("%s\n", *line);
	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	ft_strclr(*line);
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 5500000);
	if (!node->ovr)
		node->ovr = (char *)ft_memalloc(sizeof(char) * 5500000);
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
		{
			break;
		}
		ft_bzero(buf, BUFF_SIZE);
	}
	ptr = NULL;
	if (ft_strchr(node->hold, '\n'))
		*(ptr = ft_strchr(node->hold, '\n')) = '\0'; //FUCKING BROKEN
	*line = ft_strdup(node->hold);
	ft_strclr(node->hold);	
	if (ptr)
		ft_strcat(node->ovr, ptr + 1);				//strchr(node->hold, '\0'));
	else 
		ft_strcat(node->ovr, buf);
//	write(1, "	2	", 1);
//	printf("%s\n", *line);
	if (in >= 0 && ft_strlen(*line) > 0)
		return (1);
	else 
	   return (0);	
}
/*#include "get_next_line.h"
#include <stdio.h>

#include <time.h>
     

int	main()
{

	 clock_t start, end;
     
     start = clock();
	int i;
	int fd = open("large_file.txt", O_RDONLY);
	char	**line;
	line = malloc(100000);
	*line = malloc(100000);
	i = 1;
	int count = 0;
	while (count != 783)
	{	
		count++;
		i = get_next_line(76678, line);
		printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	}
	 end = clock();
	printf("%lu\n",end );
*/
     // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
/*
}
int	main()
{
	
	int i = 0;

	int	fd2 = open("one_big_fat_line.txt", O_RDONLY);
	char	**line2;
	line2 = malloc(100000);
	*line2 = malloc(100000);

	while (i > -1)
	{
		i = get_next_line(fd2, line2);
	}
//	i = get_next_line(fd2, line2);
//	printf("%s\n", *line2);
//	i = get_next_line(fd2, line2);
//	i = get_next_line(fd2, line2);
//	i = get_next_line(fd2, line2);
//	i = get_next_line(fd2, line2);
	return (0);
	//printf("%d :len :%u [%s]\n", i, ft(strlen(*line2), *line2);*/
}
