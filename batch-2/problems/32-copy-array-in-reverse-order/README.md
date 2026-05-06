# Copy Array In Reverse Order

## Methods

### Method 1
Uses an explicit counter that decrements from `ArrLength` to $0$ to pick elements from the source array.

### Method 2
Uses a mathematical formula `ArrLength - 1 - i` to calculate the reverse index directly within the loop.

## Note
**Method 2** is more concise as it eliminates the need for an extra counter variable.
Both methods effectively copy the array in reverse order and produce the same output.