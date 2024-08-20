/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:30:17 by badriano          #+#    #+#             */
/*   Updated: 2024/08/20 05:56:51 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putchar_len(char c, int current_len)
{
	write(1, &c, 1);
	current_len++;
	return (current_len);
}

int	num_len(int num, int current_len)
{
	while (num > 0)
	{
		num = num / 10;
		current_len++;
	}
	return (current_len);
}

int	ft_print_num(int num, int current_len)
{
	if (num > 9)
	{
		ft_print_num(num / 10, current_len);
	}
	write(1, &"0123456789"[num % 10], 1);
	return (num_len(num, current_len));
}

int	ft_putstr(char *str, int current_len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		current_len++;
		i++;
	}
	return (current_len);
}
