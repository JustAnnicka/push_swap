/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:49:35 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/14 00:42:31 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the TOP of stack A
// -> do nothing if there is only one or no elements
void	sa(t_stack *stack_a)
{
	int x;
	
	x = stack_a->items[stack_a->top];
	if (stack_a->top <= 0)
		return ;
	stack_a->items[stack_a->top] = stack_a->items[stack_a->top - 1];
	stack_a->items[stack_a->top - 1] = x;
	ft_printf("sa\n");
}

//pa (push a):Take the first element at the TOP of B and put it at the TOP of A
// -> Do nothing if b is empty.
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top < 0)
		return ;
	stack_a->top++;
	stack_a->items[stack_a->top] = stack_b->items[stack_b->top];
	stack_b->top--;
	ft_printf("pa\n");
}

//ra (rotate a): Shift up all elements of stack A by 1
// -> The first element becomes the last one.
void	ra(t_stack *stack_a)
{
	int	x;
	int z;
	int i;
	x = stack_a->items[0];
	i = 0;
	stack_a->items[0] = stack_a->items[stack_a->top];
	while (++i <= stack_a->top)
	{
		z = x;
		x = stack_a->items[i];
		stack_a->items[i] = z;
	}
	ft_printf("ra\n");
} 

//rra (reverse rotate a): Shift DOWN all elements of stack A by 1.
// -> The last element becomes the first one.
void	rra(t_stack *stack_a)
{
	int	x;
	int z;
	int i;

	x = stack_a->items[stack_a->top];
	i = stack_a->top;
	stack_a->items[stack_a->top] = stack_a->items[0];
	while (--i >= 0)
	{
		z = x;
		x = stack_a->items[i];
		stack_a->items[i] = z;
	}
	ft_printf("rra\n");
}
