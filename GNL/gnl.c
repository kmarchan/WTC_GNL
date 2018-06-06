/*****gnl*******/
#include "get_next_line.h"
#include <stdio.h>

int	ft_srchrep(char *str, char s, char r)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == s)
		{
			str[i] = r;
			count++;
		}	
		i++;
	}
	return (count);
}

int	get_next_line(const int fd, char **line)
{
//	int	lc;
	size_t	in;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	static	ins	*node;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (!node)
		node = (ins*)ft_memalloc(sizeof(ins));
	if (!node->hold)
		node->hold = (char *)ft_memalloc(sizeof(char) * 1000);
	if (!node->ovr)
		node->ovr = (char *)ft_memalloc(sizeof(char) * 1000);
	while ((in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_strcat(node->hold, buf);
		if  (ft_strchr(buf, '\n'))
		{
			break;
		}
		ft_bzero(buf, BUFF_SIZE);
	}
	node->lc = ft_srchrep(node->hold, '\n', '\0');
	printf("%d, %s\n", node->lc,  node->hold);
	*line = ft_strdup(node->hold);
	node->ovr = (strchr(node->hold, '\0') + 1);
//	ptr = ft_memccpy(line, node->hold, '\0', BUFF_SIZE);
	printf("%s\n", node->ovr);
	write(1, "9", 1);
//	ft_strcat(node->ovr, (memccpy(line, node->hold, '\0', BUFF_SIZE)));
	//ft_strcat(node->ovr, ptr); 
	write(1, "2", 1);
	printf("%d, %s\n", node->lc,  node->ovr);
	return (1);
}

int	main()
{
	int i;

	int	fd2 = open("file.txt", O_RDONLY);
	char	**line2;
	line2 = malloc(100000);
	*line2 = malloc(100000);

	i = get_next_line(fd2, line2);
	return (0);
	//printf("%d :len :%u [%s]\n", i, ft(strlen(*line2), *line2);
}
