/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:30:01 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/16 13:25:28 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = malloc(s1_len + s2_len + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1, s1_len + 1);
	ft_strlcat(arr, s2, s2_len + s1_len + 2);
	return (arr);
}
