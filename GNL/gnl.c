/*****gnl*******/
#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	size_t	in;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	static	ins	*node;

	ft_bzero(buf, BUFF_SIZE + 1);
//	printf("%s\n", *line);
	ft_strclr(*line);
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 5500000);
	if (!node->ovr)
		node->ovr = (char *)ft_memalloc(sizeof(char) * 5500000);
	if (node->ovr != NULL)
		ft_strcat(node->hold, node->ovr);
		ft_strclr(node->ovr);
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_strcat(node->hold, buf);
		if  (ft_strchr(buf, '\n'))
		{
			break;
		}
		ft_bzero(buf, BUFF_SIZE);
	}
	*(ptr = ft_strchr(node->hold, '\n')) = '\0';
	*line = ft_strdup(node->hold);
	ft_strclr(node->hold);	
	ft_strcat(node->ovr, ptr + 1);				//strchr(node->hold, '\0'));
	write(1, "	2	", 1);
	printf("%s\n", *line);
	if (in > 0)
		return (1);
	if (in == 0)
		return (0);
	else 
	   return (-1);	
}

int	main()
{
	int i;

	int	fd2 = open("large_file.txt", O_RDONLY);
	char	**line2;
	line2 = malloc(100000);
	*line2 = malloc(100000);

	i = get_next_line(fd2, line2);
//	printf("%s\n", *line2);
	i = get_next_line(fd2, line2);
	i = get_next_line(fd2, line2);
	i = get_next_line(fd2, line2);
	i = get_next_line(fd2, line2);
	return (0);
	//printf("%d :len :%u [%s]\n", i, ft(strlen(*line2), *line2);
}
