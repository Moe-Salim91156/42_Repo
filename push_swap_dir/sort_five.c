/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:00:42 by msalim            #+#    #+#             */
/*   Updated: 2024/10/28 16:32:18 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	int	smallest;

	smallest = get_smallest(a);
	while (smallest != a->top->value && sorted(a) == 0)
	{
		if (smallest == get_second(a))
			swap_a(a);
		else
			reverse_ra(a);
	}
	if (sorted(a) == 0)
	{
		push_b(a, b);
		sort_four(a, b);
		push_a(a, b);
	}
}
