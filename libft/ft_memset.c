/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:51:22 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/15 15:38:24 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	stuff;
	size_t			i;

	ptr = s;
	stuff = c;
	i = 0;
	while (i < n)
	{
		ptr[i] = stuff;
		i++;
	}
	return (s);
}
