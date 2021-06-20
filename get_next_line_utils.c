#include "get_next_line.h"

size_t	len_to(char	*buf, char c)
{
	size_t	i;

	i = 0;
	while (*buf != c && *buf)
	{
		buf++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_rslt;
	char	*s;
	char	*start_s1;
	char	*start_s2;

	if (!s1 || !s2)
		return (0);
	s = malloc(sizeof(char) * (len_to(s1, '\0') + (len_to(s2, '\0')) + 1));
	if (!s)
	{
		return (0);
	}
	s_rslt = s;
	start_s1 = s1;
	start_s2 = s2;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	free(start_s2);
	return (s_rslt);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res)
	{
		if ((char)c == *res)
			return (res);
		res++;
	}
	if (c == '\0')
		return (res);
	return (0);
}
