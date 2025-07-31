/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:01:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/30 14:46:35 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}

void	ft_putuns(unsigned int n, int *count)
{
	if (n == 4294967295)
	{
		ft_putstr("4294967295", count);
		return ;
	}
	if (n > 9)
		ft_putuns(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}
