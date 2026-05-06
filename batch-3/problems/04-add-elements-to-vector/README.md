# Add Elements to Vector

## Methods

### Method 1
Utilizes a `do-while` loop for the input process. The `ReadNumbers` function is defined to return a `vector<int>`, which is then assigned to the vector in the `main` function.

### Method 2
Uses a standard `while` loop with an initial character value. It employs a `void` function that updates the vector directly without returning any value, keeping the `main` function's logic more concise.

## Note
The core logic in both methods is the use of **Pass by Reference** (`&`) and `push_back()` to dynamically grow the vector. The main difference lies in the **Function Signature**: Method 1 uses a return type, while Method 2 relies entirely on the reference to reflect changes, which is a cleaner approach for updating existing containers.