/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:13:38 by msalim            #+#    #+#             */
/*   Updated: 2024/10/22 18:16:33 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include	"../libft/libft.h"

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
		printf("%d -> \n",current->value);
		current = current->next;
	}
}

int	get_third(t_stack *a)
{
	if (a->size > 2)
		return (a->top->next->next->value);
	else
		return -1;
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
		return -1;
}
/*void	sort_three(t_stack *a)
{
	if (a->size < 3)
		exit(-1);
	while ( !(peek(a) < get_second(a) && get_second(a) < get_third(a)))
	{
	if (peek(a) > get_third(a))
		rotate_a(a);
	if (get_second(a) > get_third(a)) //last two not sorted;
		swap_a(a);
	if (peek(a) > get_second(a)) // if top is bigger than second;
		swap_a(a);
	}
}*/
void sort_three(t_stack *a) {
    if (a->size < 3)
        exit(-1);

    while (!(peek(a) < get_second(a) && get_second(a) < get_third(a))) {
			 if (peek(a) > get_third(a))
            rotate_a(a); 
      else if (peek(a) > get_second(a) ) 
            swap_a(a);
			else if (get_second(a) > get_third(a))
            swap_a(a);
    }
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int			i;
	int			value;

	i = argc;
	if (argc < 2)
	{
		write(2,"ERROR\n",6);
		exit(-1);
	}
	a = init_stack();
	b = init_stack();
	while (--i > 0)
	{
		value = ft_atoi(argv[i]);
		push(a,value);
	}
	sort_three(a);
}











/*
int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	b = init_stack();
	push(a, 3);
	push(a, 2);
	push(a, 4);
	printf("stack a is : ");
	display_stack(a);
	push_b(a, b);
	printf("stack b is : ");
	display_stack(b);
	rrr(a, b);
	printf("stack a is : ");
	display_stack(a);
	free_stack(b);
	free_stack(a);
	return (0);
}*/
