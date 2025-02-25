
#include "push_swap.h"

/* BENCHMARK
For a minimalist validation you must be able to sort 100 random numbers in fewer than 700 operations.
For maximal project validation and thus to be able to achieve the bonuses, you
must be able to sort for  500 random numbers, there should be no more than 5500 operations.
 */

//POSSIBLE ERROR:
// -> arguments are not integers
// -> some arguments are bigger than integers
// -> some arguments are smaller than integers
// -> integers are duplicates

// Need to be able to take multiple arguments of numbers for a stack 

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("%d\n", stack->items[i]);
		i--;
	}
}
void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int j;

	i = a->top;
	j = b->top;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			ft_printf("%d", a->items[i]);
		ft_printf("    ");
		if (j >= 0)
		{
			ft_printf("%d", b->items[j]);
			j--;
		}
		i--;
		ft_printf("\n");
	}
	ft_printf("-    -\na    b\n");
}

int	main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	int	count;
	int	e;

	count = 0;
	if (argc < 2)
		return (argv = NULL, ft_error());
	stack_a = init_stack(&stack_a, argc - 1);
	stack_b = init_stack(&stack_b, argc - 1);
	argv++;
	fill_stack_a(&stack_a, argv);
	if (check_duplicates(&stack_a) == -1)
		return(-1);
	e = check_order(&stack_a);
	while (e != 0)
	{
		print_stacks(&stack_a, &stack_b);
		order(&stack_a, &stack_b, e);
		e = check_order(&stack_a);
		if (e == 0 && stack_a.top != stack_a.maxsize)
			e = -1;
		count++;
	}
	check_order(&stack_a);
	print_stack(&stack_a);
	//FREE STACK B
//	ft_printf("max:%d top: %d\n", stack_a.maxsize, stack_a.top);
	ft_printf("count: %d\n", count);
	ft_printf("EXIT");
}

/* int main() {
	printf("Hello, world!\n");
}
 */