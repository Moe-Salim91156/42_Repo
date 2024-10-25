/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:25:01 by msalim            #+#    #+#             */
/*   Updated: 2024/10/21 19:03:14 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	t_Node	*first;
	t_Node	*second;
	int		temp;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	first = a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *a)
{
	t_Node	*first;
	t_Node	*second;
	int		temp;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	first = a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
