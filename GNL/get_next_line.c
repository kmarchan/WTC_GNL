/*****gnl*******/
#include "get_next_line.h"
#include "libft.h"
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
