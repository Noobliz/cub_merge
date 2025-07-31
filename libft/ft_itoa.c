/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:33:31 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/21 14:50:59 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_size(int n)
{
	int		stock_n;
	size_t	size;

	stock_n = n;
	size = 0;
	if (n <= 0)
		size = 1;
	while (stock_n != 0)
	{
		size++;
		stock_n = stock_n / 10;
	}
	return (size);
}

static char	*int_min(void)
{
	char	*int_min;

	int_min = malloc(sizeof(char) * (12));
	ft_strlcpy(int_min, "-2147483648", 13);
	return (int_min);
}

static int	if_negative(int n, int *off_on)
{
	if (n >= 0)
	{
		*off_on = 0;
		return (n);
	}
	else
	{
		*off_on = 1;
		return (n * -1);
	}
}

static void	convert_digits(char *converted, int n, int size, int off_on)
{
	while (n > 0)
	{
		converted[size -1 + off_on] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*converted;
	int		off_on;

	if (n == -2147483648)
		return (int_min());
	if (n == 0)
	{
		converted = malloc(sizeof(char) * 2);
		if (!converted)
			return (NULL);
		converted[0] = '0';
		converted[1] = '\0';
		return (converted);
	}
	n = if_negative(n, &off_on);
	size = ft_size(n);
	converted = malloc(sizeof(char) * (size + off_on + 1));
	if (!converted)
		return (NULL);
	if (off_on)
		converted[0] = '-';
	convert_digits(converted, n, size, off_on);
	converted[size + off_on] = '\0';
	return (converted);
}
