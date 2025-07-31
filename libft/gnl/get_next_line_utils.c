/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:58:07 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 14:04:08 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return ((char *)ptr - (char *)str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen_gnl(dst);
	src_len = ft_strlen_gnl(src);
	if (!size)
		return (src_len);
	if (dest_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen_gnl(src);
	i = 0;
	if (dst == NULL || src == 0)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*arr;
	size_t	size;

	size = ft_strlen_gnl(s);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy_gnl(arr, s, size + 1);
	return (arr);
}
