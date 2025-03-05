/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:38:35 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/05 17:40:59 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ERROR LOCATION FUNCTION
// PA UNTIL WE HIT ERROR
// IF ERROR LOCATION == 0 do either rr, ra, ss, sa, rrr, rra 

int	error_location(t_stack *x)
{
	int	i;

	i = x->top;
	if (i != 0 && x->items[i] > x->items[0])
		return(i);
	while (i - 1 >= 0 && x->items[i] < x->items[i - 1])
		i--;
	if (i == x->top)
		return(i);
	return(--i);
}

int refill_stack_a(t_stack *a, t_stack *b, int la)
{
	int	dif_bt_a0;
	int	dif_bt_at;

	ft_printf("ENTER REFILL\n");
	dif_bt_at = a->items[a->top] - b->items[b->top];
	dif_bt_a0 = a->items[0] - b->items[b->top];
	ft_printf("bt-at: %d  a0-bt: %d last action %d\n", dif_bt_at, dif_bt_a0, la);
/* 	if (b->items[b->top] < a->items[a->top] && a->items[0] > a->items[a->top])
		pa(a, b); */
	
	if (b->top >= 1 && b->items[b->top] < b->items[b->top - 1])
		return (sb(b), 0);
	else if (b->items[b->top] < a->items[0] && a->items[0] < a->items[a->top])
		return (rra(a), 5);
	else if (b->items[b->top] > a->items[a->top])
		return (ra(a), 4);
	else if (b->items[b->top] < a->items[a->top] && la != 5)
	{
		ft_printf("TEST\n");
		return (pa(a, b), 0);
	}
	else if (la == 5 && b->items[b->top] < a->items[a->top] && a->items[0] < b->items[b->top])
	{
		ft_printf("TEST2\n");
		return (pa(a, b), 0);
	}
	else if ((b->items[b->top] < a->items[0] && dif_bt_a0 > dif_bt_at && a->items[0] < a->items[a->top]) ||( dif_bt_at < 0  && la != 4)
		||( a->items[0] > b->items[b->top] && la == 5 && b->items[b->top] < a->items[0]
		&& a->items[0] < a->items[a->top]))
		return (ft_printf("TEST3\n"), rra(a), 5);
	else if (la != 5 && ((b->items[b->top] < a->items[0] && dif_bt_a0 < dif_bt_at)
		|| (b->items[b->top] > a->items[a->top] && a->items[a->top] > a->items[0])))
		return (ra(a), 4);
	else if (b->items[b->top] < a->items[a->top])
		return (pa(a, b), 0);
	/* ft_printf("btop: %d\n", b->top); */
	return (0);
}
int order(t_stack *a, t_stack *b, int error, int la)
{
	int loc;

	loc = error_location(a);
	ft_printf("error %d, loc %d top %d\n", error, loc, a->top);
	if (b->top >= 1 && a->top >= 1)
	{
		if (b->items[b->top] < b->items[0] && a->items[a->top] > a->items[0])
			return (rr(a, b), 0);
		else if (b->items[b->top] < b->items[b->top - 1] && a->items[a->top] > a->items[a->top - 1])
			return (ss(a, b), 0);
		else if (b->items[b->top] < b->items[0])
			return (rb(b), 0);
		else if (loc == a->top && b->items[b->top] < b->items[b->top - 1])
			return (sb(b), 0);
	/* 	else if (b->items[b->top] < a->items[a->top] && a->items[0] > a->items[a->top])
			return (pa(a, b), 0); */
		else if (a->top != 2 && a->items[a->top] > b->items[b->top] && a->items[a->top] < a->items[0]
			&& a->items[a->top - 1] < b->items[b->top])
			return (pb(a, b), 0);
	}
	if (loc != a->top)
		return (pb(a, b), 0);
	if (a->top > 0)
	{
		if ((a->top >= 1 && a->items[a->top] > a->items[0] && a->items[a->top] < a->items[a->top - 1]
			&& (a->items[a->top] - a->items[0]) <= (a->items[a->top - 1] - a->items[a->top]) && la != 5)
			|| (a->top >= 1 && a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[0]
			&& a->items[a->top - 1] < a->items[0]))
			return (ra(a), 0);
		else if (a->items[a->top] > a->items[a->top - 1])
			return (sa(a), 0);
		else if ((a->items[a->top] < a->items[0] && a->items[a->top] < a->items[a->top - 1])
			|| (b->top == -1 && a->items[a->top] > a->items[0]))
			return (rra(a), 5);
		else if ((error != 1 && b->top > 0 && a->items[a->top] > b->items[b->top]) || b->top == -1)
			return (pb(a, b), 0);
	}
	return (1);
}
