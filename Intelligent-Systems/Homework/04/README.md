# Genetic algorithms

Initiate random number of states

## Three steps
1. Selection
2. Crossing
3. Mutation

Rinse and repeat

Algorithm
1. Init random population of size n
2. Foreach age in ages 
	- foreach element in population
	  - generate crossover
	  -	mutate x % of population
	  -	add to new population
	- select only best n elements
	- log best x specimen

- fitness function - given specimen close to solution (heuristic)
- crossover - get characteristics from 2 specimen
- mutation - define function
- mutation % ?
- size of n ?
- when to stop? - ages count
- how to get next population
- how to select crossover elements
- every state is good to be array

# Knapsack problem
The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

# For homework solution
- Every element in the population is a bool array, indicating whether the element at index i is selected or not
- Fitness functions - is the sum of values for the given element
- Do not work with invalid data
- Mutation % is 5-10
2. fitness - sum of values
3. do not work with invalid data
5-10% mutation
combine 2 populations and take best n