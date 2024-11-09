/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:50:17 by msalim            #+#    #+#             */
/*   Updated: 2024/11/09 18:31:22 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_Node	*current;
	t_Node	*next;

	current = a->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(a);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(t_stack *a, t_stack *b, char **array, char *arr)
{
	free_stack(a);
	free_stack(b);
	free_2d_array(array);
	free(arr);
}
