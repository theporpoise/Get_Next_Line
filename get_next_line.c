/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:26:56 by mgould            #+#    #+#             */
/*   Updated: 2016/12/23 18:36:46 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
#include <stdio.h>


int			get_next_line(const int fd, char **line)
{
	int				value;
	static void		*tmp;
	static size_t 	size;
	void			*current_line;


	size = 0;
	current_line = NULL;
	if (!tmp)
	{
		size = BUFF_SIZE;
		tmp = ft_memalloc(size);
		//printf("FIRES ONLY ONCE\n");
	}
	else if (!(ft_memchr(tmp, '\n', size)))
	{
		//current_line = tmp;
		//current_line = ft_memalloc(size);
		//current_line = ft_memcpy(current_line, tmp, size);
		printf("CURRENT LINE IS:%s", current_line);
		printf("IF HER IF\n");
	}
	else
	{
		current_line = ft_memalloc(size);
		current_line = ft_memcpy(current_line, tmp, size);
		printf("ELSE ELSE\n");
	}

	printf("tmp is:%s", tmp);
	printf("size is:%zu", size);
	printf("\nCL is:%s\n", current_line);



	if ((value = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (value < 0)
			return (-1);
		printf("you are here \n");
	}
	*line = tmp;
	return ((value > 0) ? 1 : 0);

}
