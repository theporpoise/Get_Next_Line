/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:05:09 by mgould            #+#    #+#             */
/*   Updated: 2016/12/28 19:56:52 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3
# include <libft.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_list_1
{
	void			*rest;
	void			*start;
	int				rm;
	int				fd;
	struct s_list_1	*next;
}					t_list_1;

#endif
