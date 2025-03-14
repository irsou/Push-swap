#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		pos;

	res = 0;
	sign = 1;
	pos = 0;
	if (str[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = (res * 10) + (str[pos] - '0');
		pos++;
	}
	return (res * sign);
}

size_t ft_strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }  
    return length;
}

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (length--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

int	ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t		position;

	position = 0;
	while (position < n)
	{
		if (str[position] == '\0' || str2[position] == '\0')
			return ((unsigned char)str[position]
				- (unsigned char)str2[position]);
		if (str[position] != str2[position])
			return ((unsigned char)str[position]
				-(unsigned char)str2[position]);
		position++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ptr;

	size = ft_strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, size);
	ptr[size] = '\0';
	return (ptr);
}

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s || d >= s + length)
		ft_memcpy(dest, src, length);
	else
	{
		d = d + length;
		s = s + length;
		while (length--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (dest);
}

void	*ft_memset(void *ptr, int value, size_t length)
{
	size_t			pos;
	unsigned char	*dir;

	pos = 0;
	dir = ptr;
	while (pos < length)
	{
		dir[pos] = (unsigned char)value;
		pos++;
	}
	return (dir);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_len = ft_strlen(s1) + ft_strlen (s2);
	new_str = (char *)malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s1, ft_strlen(s1));
	ft_memmove(new_str + ft_strlen(s1), s2, ft_strlen(s2));
	new_str[new_len] = '\0';
	return (new_str);
}