/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:16:32 by msalim            #+#    #+#             */
/*   Updated: 2024/10/21 16:23:24 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ra(t_stack *a)
{
	t_Node	*current;
	t_Node	*last;
	t_Node	*second_last;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	current = a->top;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	last = current;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

void	reverse_rb(t_stack *a)
{
	t_Node	*current;
	t_Node	*last;
	t_Node	*second_last;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	current = a->top;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	last = current;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_ra(a);
	reverse_rb(b);
}
