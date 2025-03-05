
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

typedef struct s_stack
{
    int	maxsize;
    int top;
    int	*items;
}		t_stack;



// STACK_A FUNCTIONS
void    fill_stack_a(t_stack *a, char **input);
void    sa(t_stack *stack_a);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rra(t_stack *stack_a);

// STACK_B FUNCTIONS
void    sb(t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    rb(t_stack *stack_b);
void    rrb(t_stack *stack_b);

// STACK_A & STACK_B FUNCTIONS
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);


// CHECK FUNCTIONS
int     check_order(t_stack *x);
int     order(t_stack *a, t_stack *b, int error, int la);
int    refill_stack_a(t_stack *a, t_stack *b, int la);
void    check_order_error_a(t_stack *stack_a, t_stack *stack_b);
void    check_order_error_b(t_stack *stack_a, t_stack *stack_b);
int     check_duplicates(t_stack *stack_a);

// UTILS FUNCTION
int     ft_error(void);
void	print_stack(t_stack *stack);
int	    error_location(t_stack *x);
t_stack init_stack(t_stack *s, int max);

#endif // PUSH_SWAP_H
