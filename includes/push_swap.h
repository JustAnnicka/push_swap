
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


int	ft_error(void);
t_stack init_stack(t_stack *s, int max);
void fill_stack_a(t_stack *a, char **input);
int check_order(t_stack *stack_a);
int check_duplicates(t_stack *stack_a);

#endif // PUSH_SWAP_H
