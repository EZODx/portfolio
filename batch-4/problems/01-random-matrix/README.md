# Random Matrix

## Methods

### Method 1
Fills a 3x3 matrix with random numbers using fixed loop limits and formats the output using `printf` for alignment.

### Method 2
A more flexible approach that uses parameters for rows and columns in functions, and utilizes `setw` from the `<iomanip>` library for precise output formatting.

## Note
**Method 2** is more professional and reusable because it allows passing dimensions as arguments and uses standard C++ manipulators for formatting.
Both methods successfully generate and display a (3x3) random matrix.