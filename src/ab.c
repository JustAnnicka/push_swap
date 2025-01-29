/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:54:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/01/29 19:48:38 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ss : sa and sb at the same time.
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	sa(stack_a);
	sb(stack_b);
}

//rr : ra and rb at the same time.
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	ra(stack_a);
	rb(stack_b);
}
//rrr : rra and rrb at the same time.
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	rra(stack_a);
	rrb(stack_b);
}