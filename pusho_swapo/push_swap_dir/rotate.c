/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:02:23 by msalim            #+#    #+#             */
/*   Updated: 2024/10/21 16:23:55 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *b)
{
	t_Node	*current;
	t_Node	*first;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	first = b->top;
	b->top = b->top->next;
	current = b->top;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_a(t_stack *a)
{
	t_Node	*current;
	t_Node	*first;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	first = a->top;
	a->top = a->top->next;
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}
