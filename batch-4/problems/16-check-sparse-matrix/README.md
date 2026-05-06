# Check Sparse Matrix

## Methods

### Method 1
Iterates through the matrix and counts both zero and non-zero elements using two separate counters, then compares them to decide if the matrix is sparse.

### Method 2
Optimizes the logic by counting only the zeros using a generic function `CountNumberInMatrix`. It then compares this count against half of the total matrix size ($Rows times Cols$).

## Note
Method 2 is more modular and mathematically cleaner. By using a helper function to count occurrences of zero and comparing it to the matrix's half-size, it avoids the need for a second counter and makes the code more reusable for other counting tasks.
A matrix is considered Sparse if the number of zeros is greater than the number of non-zero elements.