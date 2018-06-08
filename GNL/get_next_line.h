/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:19:18 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/07 14:30:01 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1000000

typedef struct list
{
	char	*ovr;
	char	*hold;
	int		in;
	int		fd;
	int		i;
}			ins;

int	get_next_line(const int fd, char **line);
<<<<<<< HEAD
=======

>>>>>>> 538a4ae27d27c0cc77073682b9608231df562114
#endif
