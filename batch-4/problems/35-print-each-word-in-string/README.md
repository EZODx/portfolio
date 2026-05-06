# Print Each Word In String

## Methods

### Method 1
Iterates through the string character by character. It prints each character as long as it's not a space; when a space is encountered, it prints a new line to separate the words.

### Method 2
Uses a delimiter-based approach (`find`, `substr`, and `erase`). It searches for spaces, extracts each word as a substring, and then removes it from the original string until no more spaces are found.

## Note
**Method 1** is a low-level approach that is very fast but can print extra new lines if there are multiple consecutive spaces. **Method 2** is more robust and professional as it handles multiple spaces correctly and treats the string as a collection of tokens (words).