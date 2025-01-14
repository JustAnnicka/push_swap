/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:58:24 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/14 00:41:50 by aehrl            ###   ########.fr       */
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
	s->top = -1;
	s->items = (int *)malloc(sizeof(int) * max);
	if (!s->items)
		ft_error();
	return (*s);
}
void fill_stack_a(t_stack *a, char **input)
{
	int	i;
	int j;

	i = a->maxsize;
	j = 0;
	while (i >= 0)
	{
		a->items[j] = ft_atoi(input[i]);
		//ft_printf("%d\n", a->items[j]);
		j++;
		i--;
	}
	a->top = j - 1;
}

 int check_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->maxsize)
	{
		j = i + 1;
		while (j <= a->maxsize)
		{
			if (a->items[i] == a->items[j])
				return (ft_error(), ft_printf("Duplicates\n"), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_order(t_stack *x, char stack)
{
	int	i;

	if (stack == 'a')
	{
		i = x->top;
		while (i - 1 >= 0)
		{
			if (x->items[i] > x->items[i - 1])
				return (-1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i + 1 <= x->top)
		{
			if (x->items[i] < x->items[i + 1])
				return (ft_printf("wrong order\n"), -1);
			i++;
		}
	}
	ft_printf("correct order\n");
	return (0);
}
