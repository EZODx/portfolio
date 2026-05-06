# Palindrome Matrix

## Methods

### Method 1
Converts each row into two strings (forward and backward) and compares them. This method is specifically hardcoded for a 3x3 matrix.

### Method 2
Uses an algorithmic approach with nested loops. It compares elements from the beginning of each row with their corresponding elements from the end ($matrix[i][j]$ vs $matrix[i][cols-1-j]$).

## Note
**Method 2** is far superior because it is dynamic (works for any matrix size) and more efficient, as it avoids string conversion and only iterates through half of the columns.