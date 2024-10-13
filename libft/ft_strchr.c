/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:34:54 by msalim            #+#    #+#             */
/*   Updated: 2024/09/02 18:45:29 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_char;

	new_char = (char *)s;
	while (*new_char)
	{
		if (*new_char == (char)c)
			return (new_char);
		new_char++;
	}
	if ((char)c == '\0')
		return (new_char);
	return (NULL);
}*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	p;

	p = c;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (p == '\0')
		return ((char *)s);
	return (NULL);
}
