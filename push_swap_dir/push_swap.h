/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:20:48 by msalim            #+#    #+#             */
/*   Updated: 2024/11/09 18:55:46 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
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
long			ft_atol(const char *nptr);
int				check_input(char **arr);
void			free_stack(t_stack *a);
void			free_2d_array(char **array);
void			free_all(t_stack *a, t_stack *b, char **array, char *arr);
char			*ft_strjoin_new(int argc, char **argv, char *sep);
int				error_manager(int argc, char *argv[]);
void			algo_decide(t_stack *a, t_stack *b);
void			send_to_a(t_stack *a, t_stack *b);
void			send_chunk_midpoint(t_stack *a, t_stack *b, t_Node *current);
void			send_chunk(t_stack *a, t_stack *b, t_Node *current);
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
void			sort_five(t_stack *a, t_stack *b);
void			sort_four(t_stack *a, t_stack *b);
int				get_smallest(t_stack *a);
int				sorted(t_stack *a);
int				is_empty(t_stack *a);
int				find_max(t_stack *a);
int				midpoint(t_stack *a);
void			find_Number(t_stack *a, t_stack *b, int *chunk, int high);
void			get_chunk(t_stack *a, t_stack *b, int min, int max);
int				determine_num_chunks(int num, t_stack *a);

#endif
