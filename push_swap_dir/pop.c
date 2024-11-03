/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:00:23 by msalim            #+#    #+#             */
/*   Updated: 2024/11/03 17:23:09 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	pop(t_stack *a)
{
	int		value;
	t_Node	*temp;

	if (a->top == NULL)
		return (-1);
	temp = a->top;
	value = temp->value;
	a->top = a->top->next;
	a->size--;
	free(temp);
	return (value);
}*/
int	pop(t_stack *a)
{
	if (a->top == NULL)
	{
		// Optionally handle empty stack case
		return (-1); // Indicate failure due to empty stack
	}
	t_Node *temp = a->top;   // Store the top node
	int value = temp->value; // Get the value from the top node
	a->top = a->top->next;   // Move the top pointer to the next node
	a->size--;               // Decrease the size of the stack
	free(temp);              // Free the memory of the popped node
	return (value);          // Return the value of the popped node
}
