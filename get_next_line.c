#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

static char	*rec_to(char *buf, char c)
{
	char	*line;
	char	*start_line;

	line = malloc(sizeof(char) * ((len_to(buf, c) + 1)));
	if (!line)
	{
		return (0);
	}
	start_line = line;
	while (*buf && *buf != c)
		*line++ = *buf++;
	*line = '\0';
	return (start_line);
}

static int	rtrn(ssize_t rs, char **jopa, char **line)
{
	char	*temp;

	if (ft_strchr(*jopa, '\n'))
	{
		*line = rec_to(*jopa, '\n');
		temp = rec_to((ft_strchr(*jopa, '\n') + 1), '\0');
		free(*jopa);
		*jopa = temp;
		return (1);
	}
	else if (!ft_strchr(*jopa, '\n') && rs == 0)
	{
		*line = rec_to(*jopa, '\0');
		free(*jopa);
		*jopa = NULL;
		return (0);
	}
	else
		return (-1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		rs;
	static char	*jopa;
	char		head[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	rs = 1;
	while (rs > 0)
	{
		rs = read(fd, head, BUFFER_SIZE);
		if (rs == -1)
            return (-1);
		head[rs] = '\0';
		if (jopa == NULL)
			jopa = rec_to(head, '\0');
		else
		{
			temp = ft_strjoin(jopa, rec_to(head, '\0'));
			free(jopa);
			jopa = temp;
		}
		if (ft_strchr(jopa, '\n'))
			break ;
	}
	return (rtrn(rs, &jopa, line));
}
