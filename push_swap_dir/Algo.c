/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:38:19 by msalim            #+#    #+#             */
/*   Updated: 2024/11/02 17:47:01 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// find min >>> DONE
// find max >>> DONE
// get the midpoint >>> DONE;
// CHUNKING >> DONE ;
// find number with respect to chunks;

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
		*chunk_boundaries = NULL; // Set the pointer to NULL after freeing
	}
}

void	find_number(t_stack *a, int *chunk_boundaries, int num_chunks);
int	*get_chunk(t_stack *a, int min, int max)
{
	int	*chunk_boundaries;
	int	i;
	int	chunk_range;
	int	num_chunks;

	i = 0;
	if (a->size >= 100) // 100 or bigger
		num_chunks = (max - min + 1) / 10;
	else if (a->size >= 10) //bigger or equals to 10
		num_chunks = 5;
	else  // less than 10
		num_chunks = 3;
	chunk_range = num_chunks;              // 100 / 5 = 20
	chunk_boundaries = malloc(num_chunks * 2 * sizeof(int));
	if (!chunk_boundaries)
		return (NULL);
	while (i < num_chunks)
	{
		chunk_boundaries[2 * i] = min + i * chunk_range; // start boundary
		if (i == num_chunks - 1)
			chunk_boundaries[2 * i + 1] = max;
		else
			chunk_boundaries[2 * i + 1] = min + (i + 1) * chunk_range - 1;
				// end boundary next value;
		i++;
	}
	find_number(a,chunk_boundaries,num_chunks);
	for (i = 0; i < num_chunks * 2; i++)
	{
		printf("Chunk to %d\n", chunk_boundaries[i]);
	}
	return (chunk_boundaries);
}

void	find_number(t_stack *a, int *chunk_boundaries, int num_chunks)
{
	t_Node	*current;
	int		start;
	int		i;
	int		end;

	// search for the number in the chunk;
	// locate its position if under the midpoint or upper
	// calculate if uppper how many rotate, lower how many reverse_rotate;
	current = a->top;
	i = 0;
	while (i < num_chunks)
	{
		start = chunk_boundaries[2 * i];
		end = chunk_boundaries[2 * i + 1];
	current = a->top;
		while (current != NULL)
		{
			if (current->value >= start && current->value <= end) {
                printf("Value %d found in chunk %d: start = %d, end = %d\n",
                       current->value, i + 1, start, end);
            }
	current = current->next;
		}
	i++;
	}
}

