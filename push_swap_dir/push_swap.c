/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:13:38 by msalim            #+#    #+#             */
/*   Updated: 2024/11/09 18:33:00 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	algo_decide(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		get_chunk(a, b, (get_smallest(a)), (find_max(a)));
		send_to_a(a, b);
	}
}

int	get_smallest(t_stack *a)
{
	t_Node	*current;
	int		smallest;

	current = a->top;
	smallest = current->value;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**numbers;
	char	*joined;

	joined = NULL;
	numbers = NULL;
	a = init_stack();
	b = init_stack();
	joined = ft_strjoin_new(argc, argv, " ");
	numbers = ft_split(joined, ' ');
	i = 0;
	while (numbers[i] != NULL)
		i++;
	while (--i >= 0)
		push(a, ft_atoi(numbers[i]));
	if (!check_input(numbers) || sorted(a) == 1)
	{
		free_all(a, b, numbers, joined);
		exit(EXIT_FAILURE);
	}
	algo_decide(a, b);
	free_all(a, b, numbers, joined);
}
