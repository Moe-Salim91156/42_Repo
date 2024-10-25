/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:20:48 by msalim            #+#    #+#             */
/*   Updated: 2024/10/22 19:40:05 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
	int			value;
	struct Node	*next;
}				t_Node;

typedef struct stack
{
	int			size;
	t_Node		*top;
}				t_stack;

void			swap_a(t_stack *a);
void			swap_b(t_stack *a);
void			ss(t_stack *a, t_stack *b);
void			push(t_stack *a, int value);
void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			rotate_a(t_stack *a);
void			rotate_b(t_stack *b);
void			reverse_ra(t_stack *a);
void			reverse_rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				pop(t_stack *a);
void			sort_three(t_stack *a);
int				peek(t_stack *a);
int				get_second(t_stack *a);
int				get_third(t_stack *a);
#endif
