/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:12 by msalim            #+#    #+#             */
/*   Updated: 2024/11/05 18:04:14 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, int value)
{
	t_Node	*node;

	node = malloc(sizeof(t_Node));
	if (!node)
		return ;
	node->value = value;
	node->next = a->top;
	a->top = node;
	a->size++;
}

void	push_a(t_stack *b, t_stack *a)
{
	t_Node	*temp;

	if (b->top == NULL)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *b, t_stack *a)
{
	t_Node	*temp;

	if (b->top == NULL)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	write(1, "pb\n", 3);
}
