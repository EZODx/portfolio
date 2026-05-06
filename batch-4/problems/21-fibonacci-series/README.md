# Fibonacci Series

## Methods

### Method 1
Uses a clever mathematical trick with only two variables (`prev1`, `prev2`) to update the sequence without needing a temporary third variable for the sum.

### Method 2
Follows the standard logic by using three variables (`febNumber`, `prev1`, `prev2`) to calculate the sum and then shift the values forward in each iteration.

### Method 3
Prints the initial value "1" outside the loop, then uses the three-variable logic starting the iteration from the second element.

## Note
**Method 1** is the most memory-efficient (using fewer variables), while **Method 2 and 3** are more readable and follow the traditional mathematical definition of the Fibonacci sequence ($F_n = F_{n-1} + F_{n-2}$).