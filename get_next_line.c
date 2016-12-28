#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
#include <stdio.h>

t_file	*make_t_file(void *rest, int rm, int fd, int is_end)
{
	t_file	*newlist;

	if(!(newlist = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if(!(newlist->rest = ft_memalloc(rm)))
		return (NULL);
	if (rest)
		ft_memcpy((newlist->rest), rest, rm);
	newlist->rm = rm;
	newlist->fd = fd;
	newlist->is_end = is_end;
	newlist->start = newlist->rest;
	newlist->next = NULL;
	return (newlist);
}

void	*ft_memappend(void *dst, void *src, size_t dst_size, size_t src_size)
{
	void *appended;
	void *tmp;

	if (!(appended = ft_memalloc(src_size + dst_size)))
		return (NULL);
	if (!dst)
	{
		appended = ft_memcpy(appended, src, src_size);
		return (appended);
	}
	else if (!src)
	{
		appended = ft_memcpy(appended, dst, dst_size);
	}
	else
	{
		tmp = appended;
		ft_memcpy(appended, dst, dst_size);
		tmp += dst_size;
		ft_memcpy(tmp, src, src_size);
	}
	free(dst);
	return (appended);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*prev;
	unsigned char	buf[BUFF_SIZE];
	void			*seg;
	int				len;
	long			dif;

	len = 0;
	dif = 0;
	seg = NULL;
	if (!prev)
	{
		prev = make_t_file(NULL, BUFF_SIZE, fd, BUFF_SIZE);
	}
	else if (!(ft_memchr((prev->rest), '\n', prev->rm))) // && prev->rm > 0)
	{
		seg = ft_memappend(seg, prev->rest, len, prev->rm);
		len += prev->rm;
	}
	else if ((dif = (ft_memchr((prev->rest), '\n', prev->rm) - prev->rest)) > -1)
	{
		*line = ft_memalloc(dif + 1);
		*line = ft_memcpy(*line, prev->rest, dif);
		((char *)*line)[dif] = '\0';
		prev->rm = prev->rm - (dif + 1);
		prev->rest = prev->rest + (dif + 1);
		return (1);
	}
	else
		printf("error\n");
	ft_bzero(prev->start, BUFF_SIZE);
	prev->rm = BUFF_SIZE;
	prev->rest = prev->start;
	while ((prev->is_end = read(fd, buf, BUFF_SIZE)))
		{
			if (prev->is_end < 0)
				return (-1);
			if (!(ft_memchr(buf, '\n', prev->is_end)))
			{
				seg = ft_memappend(seg, buf, len, prev->is_end);
			}
			else if (ft_memchr(buf, '\n', prev->is_end))
			{

				dif = (ft_memchr(buf, '\n', prev->is_end)) - (void *)buf;
				seg = ft_memappend(seg, buf, len, dif);
				prev->rm = prev->is_end - (dif + 1);
				prev->rest = ft_memcpy(prev->rest, (buf + dif + 1), prev->rm);
				len = len + dif;
				break;
			}
			len += prev->is_end;
		}

	*line = ft_memappend(seg, ft_memset(ft_memalloc(1), '\0', 1), (len), 1);
	//MAY HAVE TO FREE THAT ONE STUPID BYTE :-( or break into mult func//
	return ((prev->is_end > 0) ? 1 : 0);
}










