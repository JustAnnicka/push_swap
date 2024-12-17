
#include "push_swap.h"

/* BENCHMARK
For a minimalist validation you must be able to sort 100 random numbers in fewer than 700 operations.
For maximal project validation and thus to be able to achieve the bonuses, you
must be able to sort for  500 random numbers, there should be no more than 5500 operations.
 */

//POSSIBLE ERROR:
// -> arguments are not integers
// -> some arguments are bigger than intefers
// -> integers are duplicates

int	main(int argc, char *argv[])
{
	t_stack stack_a;
	//t_stack *stack_b;

	if (argc < 2)
		return (argv = NULL, ft_error());
	stack_a = init_stack(&stack_a, argc - 1);
	argv++;
	fill_stack_a(&stack_a, argv);
	ft_printf("max:%d top: %d\n", stack_a.maxsize, stack_a.top);
	ft_printf("EXIT");
	
}

/* int main() {
	printf("Hello, world!\n");
}
 */