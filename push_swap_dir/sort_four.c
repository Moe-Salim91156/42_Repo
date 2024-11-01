/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:28 by msalim            #+#    #+#             */
/*   Updated: 2024/10/28 16:31:07 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_four(t_stack *a, t_stack *b)
{
	int	smallest;

	smallest = get_smallest(a);
	while (smallest != a->top->value)
	{
		if (smallest == get_second(a))
			swap_a(a);
		else
			reverse_ra(a);
	}
	if (sorted(a) == 0)
	{
		push_b(a, b);
		sort_three(a);
		push_a(a, b);
	}
}
