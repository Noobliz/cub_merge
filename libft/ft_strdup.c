/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:33:32 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/21 13:05:39 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	size;

	size = ft_strlen(s);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s, size + 1);
	return (arr);
}
