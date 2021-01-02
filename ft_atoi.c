/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:46:58 by bahn              #+#    #+#             */
/*   Updated: 2021/01/02 12:22:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_isspace(char *str)
{
	while (*str != '\0' && (*str == ' ' || *str == '\f' || *str == '\n' ||
	*str == '\r' || *str == '\t' || *str == '\v'))
	{
		str++;
	}
	return (str);
}

int		ft_atoi(char *str)
{
	long long sign;
	long long nbr;

	sign = 1;
	nbr = 0;
	str = ft_isspace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		else if (*str == '+')
			sign *= 1;
		str++;
	}
	while ((*str != '\0') && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	if (nbr * sign > 2147483647)
		return (0);
	if (nbr * sign < -2147483648)
		return (-1);
	return (nbr * sign);
}
