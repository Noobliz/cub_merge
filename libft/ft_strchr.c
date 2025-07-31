/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:25:28 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/21 12:27:36 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)str + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) str + i);
	return (NULL);
}
