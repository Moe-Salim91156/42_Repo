/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_refactor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:35:55 by msalim            #+#    #+#             */
/*   Updated: 2024/11/05 17:06:41 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// send the chunks from a to b
void	send_chunk_midpoint(t_stack *a, t_stack *b, t_Node *current)
{
	int		mid_index;
	int		position;
  t_Node	*mid;

	mid = a->top;
	mid_index = a->size / 2 + 1;
	position = 0;
	while (mid != NULL && mid != current)
	{
    mid = mid->next;
		position++;
	}
	while (a->top->value != current->value)
	{
    if (position <= mid_index)
      rotate_a(a);
    else
      reverse_ra(a);
	}
	push_b(a, b);
}
// chunking is done, b is now semi sorted 
// we want to send the numbers back to a sorted 
// we first must apply the sort 3 to whats left in a;
int get_position(t_stack *b, int max)
{
  t_Node  *current;
  int position;

  current = b->top;
  position = 0;
  while (current != NULL && current->value != max)
  {
    position++;
    current = current->next;
  }
  return (position);
}

void  send_to_a(t_stack *a, t_stack *b)
{
  int max;
  int position;
  while (b->size > 0)
  {
    max = find_max(b);
    position = get_position(b,max);
      if (position <= b->size / 2 + 1)
        while (b->top->value != max)
          rotate_b(b);
      else
        while (b->top->value != max)
          reverse_rb(b);
    push_a(b,a);
  }

}
