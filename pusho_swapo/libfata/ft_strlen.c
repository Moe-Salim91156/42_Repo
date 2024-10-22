/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:19 by msalim            #+#    #+#             */
/*   Updated: 2024/09/07 19:05:39 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<unistd.h>
#include	"libft.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
/*int	main(void)
{
	printf("%ld\n", ft_strlen("hel"));
}*/
