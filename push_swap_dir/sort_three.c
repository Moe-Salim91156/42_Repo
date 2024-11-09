/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:38:02 by msalim            #+#    #+#             */
/*   Updated: 2024/11/07 14:39:09 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_third(t_stack *a)
{
	if (a->size > 2)
		return (a->top->next->next->value);
	else
		return (-1);
}

int	get_second(t_stack *a)
{
	if (a->size > 2)
		return (a->top->next->value);
	else
		return (-1);
}

int	peek(t_stack *a)
{
	if (a->top != NULL)
		return (a->top->value);
	else
		return (-1);
}

void	sort_three(t_stack *a)
{
	while (sorted(a) == 0)
	{
		while (!(peek(a) < get_second(a) && get_second(a) < get_third(a)))
		{
			if (peek(a) > get_third(a))
				rotate_a(a);
			else if (peek(a) > get_second(a))
				swap_a(a);
			else if (get_second(a) > get_third(a))
				swap_a(a);
		}
	}
}
