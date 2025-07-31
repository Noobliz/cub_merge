/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:30:24 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/15 19:12:53 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	s_len;
	size_t	max_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	max_len = s_len - start;
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		max_len = s_len - start;
	else
		max_len = len;
	arr = malloc(sizeof(char) * max_len + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s + start, max_len + 1);
	return (arr);
}
