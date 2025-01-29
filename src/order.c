/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:38:35 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/29 20:13:50 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
//check if a_top && a_top-1 are in correct order
//check if a_0 < a_top - rra
//if errors > 1 pa
//
/* void order_stack_a(t_stack *a, t_stack *b, int error)
{
	
} */

void refill_stack_a(t_stack *a, t_stack *b)
{
	/* static int	count;

	if (!count) 
		count = a->top; */
	if(b->items[b->top] > a->items[a->top])
	{
		while (b->items[b->top] < a->items[0])
			rra(a);
		if (a->top != a->maxsize)
			refill_stack_a(a, b);
	}
	if (b->items[b->top] < b->items[0])
		rrb(b);
	if (b->items[0] > b->items[b->top])
		rr(a, b);
	else if (b->items[b->top] < b->items[b->top -1])
		sb(b);
	while (b->items[b->top] < a->items[a->top])
		pa(a, b);
	/* else if(b->items[b->top] > a->items[a->top])
	{
		while (b->items[b->top] < a->items[0])
		{
			count--;
			rra(a);
		}
		if (a->top != a->maxsize && count > 0)
			refill_stack_a(a, b);
	} */
	//while (a->items[a->top])
}
void order(t_stack *a, t_stack *b, int error)
{
	/* if (a->items[a->top] > a->items[0])
		rra(a); */
	if (a->items[a->top] > a->items[0])
		ra(a);
	else if (a->items[a->top] > a->items[a->top - 1] && error == 1)
		sa(a);
	else if (error != -1)
		pb(a, b);
	if (b->top > 0)
	{
		if (a->items[a->top] > a->items[0]
			&& b->items[b->top] < b->items[0])
			rr(a, b);
		else if (a->items[a->top] > a->items[a->top - 1]
			&& b->items[b->top] < b->items[b->top - 1])
			ss(a, b);
		else if (b->items[b->top] < b->items[0])
			rb(b);
		else if (b->items[b->top] < b->items[b->top - 1])
			sb(b);
		// do calc to see if diff is smaller to btm to check for a rb rather than a switch
	}
	if (error == -1)
		refill_stack_a(a, b);
}
