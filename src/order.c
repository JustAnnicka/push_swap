/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:07:54 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/15 18:39:34 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_location(t_stack *x, char stack)
{
	int	i;

	if (stack == 'a')
	{
		i = x->top;
		while (i - 1 >= 0 && x->items[i] < x->items[i - 1])
			i--;
		if (i == x->top)
			return(i);
		return(--i);
	}
	else
	{
		i = 0;
		while (i + 1 <= x->top && x->items[i] < x->items[i + 1])
			i++;
		if (i == 0)
			return(0);
		return(i);
	}
}
int	lowest_number(t_stack *x)
{
	int	i;
	int y;

	i = 0;
	y = x->items[i];
	while (i <= x->top)
	{
		//ft_printf("%d ", x->items[i]);
		if (x->items[i] < y)
			y = x->items[i];
		i++;
	}
	if (x->items[x->top] < y)
		y = x->items[x->top];
	//ft_printf("\n");
	return(y);
}
int	highest_number(t_stack *x)
{
	int	i;
	int y;

	i = 0;
	y = x->items[i];
	while (i <= x->top)
	{
		if (x->items[i] > y)
			y = x->items[i];
		i++;
	}
	if (x->items[x->top] > y)
		y = x->items[x->top];
	return(y);
}

void check_order_error_a(t_stack *a, t_stack *b)
{
	int e;
	int	x;
	int l;
	int h;

	e = error_location(a, 'a');
	l = lowest_number(a);
	h = highest_number(a);
	x = a->top;
	ft_printf("\ne[%d] - %d\n", e, a->items[e]);
	while(a->items[e] >= a->items[x] && x > 0)
		x--;
	ft_printf("x[%d] - %d\n", x, a->items[x]);
	ft_printf("l - %d\n", l);
	if (a->items[a->top] < a->items[a->top - 1] && ((e == 0 && x == a->top ) || (e == a->top && a->items[0] < a->items[a->top - 1]) || a->items[0] == l))
		rra(a);
	else if (x != (a->top - 1) && ((e == a->top && a->items[a->top] > a->items[0]) || a->items[a->top] == h 
		|| (x == a->top && a->items[a->top] > a->items[0]) || (a->items[a->top] != l && a->items[0] > a->items[a->top])))
		ra(a);
	else if ((e == a->top && a->items[e] > a->items[a->top - 1] && a->items[a->top] != h))
		sa(a);
	else
		pb(a, b);
}

void check_order_error_b(t_stack *a, t_stack *b)
{
	int e;
	int	x;

	x = error_location(b, 'b');
	e = b->top;
	ft_printf("\nB  e[%d] - %d\n", e, b->items[e]);
	while(b->items[e] >= b->items[x] && x > 0)
		x--;
	ft_printf("B  x[%d] - %d\n", x, b->items[x]);
	if ((e == b->top && b->items[e] < b->items[b->top - 1]) && (e == a->top && a->items[e] < a->items[a->top - 1]))
		ss(a, b);
	else if ((e == b->top && x == 0 && b->items[e] < b->items[x]) || (x == b->top && b->items[b->top] < b->items[0]))
		rb(b);
	else if ((e == 0 && x == b->top ) || (e == b->top && b->items[0] > b->items[b->top - 1]))
		rrb(b);
	else if ((e == b->top && b->items[e] < b->items[b->top - 1]))
		sb(b);
	else
		pa(a, b);
	
}
