/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:22:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/21 12:28:23 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (str[i])
		i++;
	if (str[i] == (unsigned char) c)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == (unsigned char) c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
