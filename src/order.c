/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:07:54 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/14 01:09:53 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_location(t_stack *a)
{
	int	i;

	i = a->top;
	while (i - 1 >= 0 && a->items[i] < a->items[i - 1])
		i--;
	if (i == a->top)
		return (i);
	//ft_printf("x - %d\n", i);
	return (--i);
}

void check_order_error(t_stack *a, t_stack *b)
{
	int e;
	int	x;

	e = error_location(a);
	x = a->top;
	ft_printf("\ne[%d] - %d\n", e, a->items[e]);
	while(a->items[e] >= a->items[x] && x > 0)
		x--;
	ft_printf("x[%d] - %d\n", x, a->items[x]);
	if ((e == 0 && x == a->top) || (e == a->top && a->items[0] < a->items[a->top - 1]))
		rra(a);
	else if ((e == a->top && x == 0 && a->items[e] > a->items[x]))
		ra(a);
	if ((e == a->top && a->items[e] > a->items[a->top - 1]))
		sa(a);
	else
		pb(a, b);
}
