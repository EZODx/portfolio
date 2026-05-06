# Replace Words

## Methods

### Method 1
Splits the string into a vector of words (tokens). It then iterates through the vector, checks if a word matches the target, replaces it if necessary, and finally joins the words back into a single string.

### Method 2
Uses the built-in `string::find` and `string::replace` functions. It locates the position of the target word and replaces it directly within the original string in a loop until all occurrences are handled.

## Note
**Method 2** is more efficient and cleaner as it utilizes standard library functions and avoids the overhead of splitting and rebuilding the string. **Method 1** is useful if you need to perform additional logic on each word individually during the replacement process.