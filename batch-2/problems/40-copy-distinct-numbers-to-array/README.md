# Copy Distinct Numbers To Array

## Methods

### Method 1
Uses a custom `IsDistinct` function with an internal counter to verify if a number exists in the second array before adding it.

### Method 2
Utilizes a more modular approach with `IsNumberInArray` and `FindNumberPositionInArray` functions to check for duplicates.

## Note
**Method 2** is cleaner and more modular, making it easier to reuse logic.
Both methods effectively extract unique elements and produce the same distinct array.