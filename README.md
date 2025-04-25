# Push-swap

Push_swap is a complex sorting algorithm that arranges the numbers in ascending order from a stack with an arbitrary amount of unique positive and negative integers using the least amount of operations possible. At a minimun, it must be able to sort 100 numbers in fewer than 700 movements. The project reaches it maximun when being able to sort 500 numbers in fewer than 5500 numbers.

Basic movements:
Swap: swaps the first two elements of a stack.
- sa (swap stack a)
- sb (swap stack b)
- sr (swap stack a & stack b)

Push: Removes the first element of a stack and inserts it at the start of another stack
- pa (push b1 into stack a)
- pb (push a1 into stack b)

Rotate: Shifts all elements of a stack up by one position, so the first element becomes the last one
- ra (rotate stack a)
- rb (rotate stack b)
- rr (rotate stack a & stack b)

Reverse rotate: Shifts all elements of a stack down by one position, so the last element becomes the first
- rra (reverse rotate stack a)
- rrb (reverse rotate stack b)
- rrr (reverse rotate stack a & stack b)

Example with 3 numbers:
- `1`-`2`-`3`  ✔️
- `2`-`1`-`3` => sa => `1`-`2`-`3`
- `3`-`1`-`2` => ra => `1`-`2`-`3`
- `2`-`3`-`1` => rra => `1`-`2`-`3` 
- `3`-`2`-`1` => sa => `2`-`3`-`1` => rra `1`-`2`-`3` 
- `1`-`3`-`2` => sa => `3`-`1`-`2` => ra `1`-`2`-`3` 


gcc




Checking memory leaks

valgrind -s --leak-check=full ./push_swap 42
valgrind --leak-check=full ./push_swap "42" 2
valgrind --leak-check=full ./push_swap 42 "2"
valgrind --leak-check=full ./push_swap "42" 2  aaaa
valgrind --leak-check=full ./push_swap "42" 2  111111111111
valgrind --leak-check=full ./push_swap "42" "2"7"4"3"9"
valgrind --leak-check=full ./push_swap 42 "333"
valgrind --leak-check=full ./push_swap "42" "333"
valgrind --leak-check=full ./push_swap 42 333
valgrind --leak-check=full ./push_swap "42 5" 2
valgrind --leak-check=full ./push_swap 42 "5 2"
valgrind --leak-check=full ./push_swap 42 2 54 -14 37
ARG="9 3 7 1 5 8 -6 4 2 0"; valgrind --leak-check=full ./push_swap $ARG






