/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:13:38 by msalim            #+#    #+#             */
/*   Updated: 2024/11/05 17:29:26 by msalim           ###   ########.fr       */
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

void	free_stack(t_stack *a)
{
	t_Node	*current;
	t_Node	*next;

	current = a->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(a);
}

void	display_stack(t_stack *a)
{
	t_Node	*current;

	current = a->top;
	if (!current)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	while (current != NULL)
	{
		printf("%d -> \n", current->value);
		current = current->next;
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
	int		value;

	i = argc;
	a = init_stack();
	b = init_stack();
	if (argc < 2)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	while (--i > 0)
	{
		value = ft_atoi(argv[i]);
		push(a, value);
	}
	if (sorted(a) == 1)
	{
		write(1, "sor\n", 4);
		return (0);
	}
	get_chunk(a, b, (get_smallest(a)), (find_max(a)));
	send_to_a(a, b);
}
