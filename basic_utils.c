/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:04 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/15 19:52:04 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		pos;

	res = 0;
	sign = 1;
	pos = 0;
	if (str[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = (res * 10) + (str[pos] - '0');
		pos++;
	}
	return (res * sign);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int is_valid_digit(char c)
{
  return (c >= '0' && c <= '9');
}

int	is_valid_int(const char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_valid_digit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
