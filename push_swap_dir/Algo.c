/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:38:19 by msalim            #+#    #+#             */
/*   Updated: 2024/11/01 19:09:11 by msalim           ###   ########.fr       */
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

	midpoint_index = a->size / 2;
	return (midpoint_index);
}


void free_chunk_boundaries(int **chunk_boundaries) {
    if (*chunk_boundaries != NULL) {
        free(*chunk_boundaries);
				*chunk_boundaries = NULL;  // Set the pointer to NULL after freeing
    }
}

int	*get_chunk(t_stack *a, int min, int max)
{
	int	*chunk_boundaries;
	int	i;
	int	chunk_range;
	int	num_chunks;

	i = 0;
	 if (a->size <= 100)
		num_chunks = 5;
	else 
		num_chunks = 2;
	chunk_range = (max - min + 1) / num_chunks; // 100 / 5 = 20
	chunk_boundaries = malloc(num_chunks * 2 * sizeof (int)); // 2 for the starting bound , and the end for each chunk
	if (!chunk_boundaries)
		return (NULL);
	while (i < num_chunks)
	{
		chunk_boundaries[2 * i] = min + i * chunk_range; // start boundary
		if (i == num_chunks - 1)
			chunk_boundaries[2 * i + 1] = max;
		else
			chunk_boundaries[2 * i + 1] = min + (i + 1) * chunk_range - 1 ; // end boundary next value;
		i++;
	}
	 for (i = 0; i < num_chunks; i++) {
        printf("Chunk %d: %d to %d\n", i + 1, chunk_boundaries[2 * i], chunk_boundaries[2 * i + 1]);
    }
	return (chunk_boundaries);
}
