/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:01:24 by bahn              #+#    #+#             */
/*   Updated: 2021/01/01 20:09:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*s1_first;
	char	*s1_last;

	if (!s1)
		return (NULL);
	s1_first = (char *)s1;
	s1_last = (char *)s1 + ft_strlen((char *)s1) - 1;
	while (ft_strchr((char *)set, *s1_first))
		s1_first++;
	while (ft_strchr((char *)set, *s1_last))
		s1_last--;
	if (s1_first > s1_last)
	{
		result = (char *)malloc(1);
		*result = '\0';
	}
	else
	{
		result = (char *)malloc(s1_last - s1_first + 2);
		if (!result)
			return (0);
		ft_strlcpy(result, s1_first, s1_last - s1_first + 2);
	}
	return (result);
}
