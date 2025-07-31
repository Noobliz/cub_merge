/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:42 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 13:28:33 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_puthexa(unsigned int n, int *count, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		ft_puthexa(n / 16, count, c);
	ft_putchar(base[n % 16], count);
}

void	ft_putadd(unsigned long int n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_putadd(n / 16, count);
	ft_putchar(base[n % 16], count);
}

void	ft_flags(va_list current_arg, char c, int *count)
{
	unsigned long int	stock;

	if (c == 'c')
		ft_putchar(va_arg(current_arg, int), count);
	else if (c == 's')
		ft_putstr(va_arg(current_arg, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(current_arg, int), count);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(current_arg, unsigned int), count, c);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 'u')
		ft_putuns(va_arg(current_arg, unsigned int), count);
	else if (c == 'p')
	{
		stock = va_arg(current_arg, unsigned long int);
		if (!stock)
		{
			ft_putstr("(nil)", count);
			return ;
		}
		ft_putstr("0x", count);
		ft_putadd(stock, count);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	current_arg;
	int		i;
	int		count;

	va_start(current_arg, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_flags(current_arg, str[i], &count);
		}
		else if (str[i] != '%')
		{
			count += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(current_arg);
	return (count);
}
