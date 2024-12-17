/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:58:24 by aehrl             #+#    #+#             */
/*   Updated: 2024/12/15 19:08:13 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (-1);
}
t_stack init_stack(t_stack *s, int max)
{
	s->maxsize = max - 1;
	s->top = 0;
	s->items = (int *)malloc(sizeof(int) * max);
	if (!s->items)
		ft_error();
	return (*s);
}
void fill_stack_a(t_stack *a, char **input)
{

	while (a->top <= a->maxsize)
	{
		a->items[a->top] = ft_atoi(input[a->top]);
		ft_printf("%d\n", a->items[a->top]);
		a->top++;
	}
	a->top--;
}

/* int check_duplicates(t_stack *a)
{
	
}

int check_order(t_stack *a)
{
	
} */