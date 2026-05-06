# My Floor Function

## Methods

### Method 1
Uses a helper function `GetFraction` to check for fractional parts before deciding whether to round down.

### Method 2
Directly applies the logic: returning the integer part for positive numbers, and subtracting 1 from the integer part for negative numbers.

## Note
**Method 2** is more concise as it achieves the same result with fewer conditional checks and no extra functions.
Both methods accurately simulate the built-in C++ `floor()` function.