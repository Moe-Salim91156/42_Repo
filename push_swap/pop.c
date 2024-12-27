/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:00:23 by msalim            #+#    #+#             */
/*   Updated: 2024/11/05 16:07:46 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *a)
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
}
