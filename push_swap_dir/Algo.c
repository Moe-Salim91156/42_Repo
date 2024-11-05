/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:38:19 by msalim            #+#    #+#             */
/*   Updated: 2024/11/05 17:20:59 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_number(t_stack *a, t_stack *b, int *chunk_boundaries,
			int num_chunks);

int	find_max(t_stack *a)
{
	t_Node	*current;
	int		max;

	current = a->top;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	midpoint(t_stack *a)
{
	int	midpoint_index;

	midpoint_index = a->size / 2 + 1;
	return (midpoint_index);
}

void	free_chunk_boundaries(int **chunk_boundaries)
{
	if (*chunk_boundaries != NULL)
	{
		free(*chunk_boundaries);
		*chunk_boundaries = NULL;
	}
}

int	*get_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	*chunk_boundaries;
	int	i;
	int	chunk_range;
	int	num_chunks;

	i = 0;
	if (a->size >= 100)
		num_chunks = 10;
	else if (a->size >= 10)
		num_chunks = 5;
	else
		num_chunks = 3;
	chunk_range = (max - min + 1) / num_chunks;
	chunk_boundaries = malloc(num_chunks * 2 * sizeof(int));
	if (!chunk_boundaries)
		return (NULL);
	while (i < num_chunks)
	{
		chunk_boundaries[2 * i] = min + i * chunk_range;
		chunk_boundaries[2 * i + 1] = min + (i + 1) * chunk_range - 1;
		i++;
	}
	find_number(a, b, chunk_boundaries, num_chunks);
	return (chunk_boundaries);
}

void	find_number(t_stack *a, t_stack *b, int *chunk_boundaries,
		int num_chunks)
{
	int		start;
	int		end;
	int		i;
	t_Node	*current;

	i = 0;
	while (i < num_chunks && a->size > 0)
	{
		start = chunk_boundaries[2 * i];
		end = chunk_boundaries[2 * i + 1];
		current = a->top;
		while (current != NULL && a->size > 0)
		{
			if (current->value >= start && current->value <= end)
			{
				send_chunk_midpoint(a, b, current);
				current = a->top;
			}
			else
				current = current->next;
		}
		i++;
	}
}
