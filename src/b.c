/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:51:58 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/14 19:46:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sb (swap b): Swap the first 2 elements at the TOP of stack B.
// -> do nothing if there is only one or no elements
void	sb(t_stack *stack_b)
{
	int x;
	
	x = stack_b->items[stack_b->top];
	if (stack_b->top <= 0)
		return ;
	stack_b->items[stack_b->top] = stack_b->items[stack_b->top - 1];
	stack_b->items[stack_b->top - 1] = x;
	ft_printf("sb\n");
}

//pb (push b):Take the first element at the TOP of A and put it at the TOP of B
// -> do nothing if there is only one or no elements
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top <= 0)
		return ;
	stack_b->top++;
	stack_b->items[stack_b->top] = stack_a->items[stack_a->top];
	stack_a->top--;
	ft_printf("pb\n");
	//ft_printf("top %d\n", stack_a->top);
}

//rb (rotate b): Shift UP all elements of stack B by 1.
// -> The first element becomes the last one.
void	rb(t_stack *stack_b)
{
	int	x;
	int z;
	int i;
	x = stack_b->items[0];
	i = 0;
	stack_b->items[0] = stack_b->items[stack_b->top];
	while (++i <= stack_b->top)
	{
		z = x;
		x = stack_b->items[i];
		stack_b->items[i] = z;
	}
	ft_printf("rb\n");
}

//rrb (reverse rotate b): Shift DOWN all elements of stack B by 1.
// -> The first element becomes the last one.
void	rrb(t_stack *stack_b)
{
	int	x;
	int z;
	int i;

	x = stack_b->items[stack_b->top];
	i = stack_b->top;
	stack_b->items[stack_b->top] = stack_b->items[0];
	while (--i >= 0)
	{
		z = x;
		x = stack_b->items[i];
		stack_b->items[i] = z;
	}
	ft_printf("rrb\n");
}