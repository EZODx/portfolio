# Sum Each Row In Matrix

## Methods

### Method 1
Calculates the sum of each row using a nested loop within a single function and resets the sum counter after printing each row's result.

### Method 2
Uses a more modular approach by creating a separate function `RowSum` to calculate the total for a specific row, which is then called inside a loop.

## Note
**Method 2** is more professional because it follows the principle of "Single Responsibility" by isolating the summation logic into its own function.
Both methods accurately calculate and display the sum of each row in a (3x3) matrix.