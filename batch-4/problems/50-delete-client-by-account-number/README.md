# Delete Client By Account Number

## Methods

### Method 1 & 2 (Unified Logic)
The program handles deletion by loading file data into a vector, searching for the client, and marking them with a boolean flag (`MarkForDelete`). Finally, it overwrites the file with only the records that are not marked.

## Key Difference
**Method 2** is more flexible as its saving function accepts the **filename as a parameter**, whereas **Method 1** relies on a hardcoded global constant.

## Note
This approach uses **Logical Deletion** via vectors to ensure data integrity. By confirming the deletion in memory before updating the physical file, it prevents accidental data loss during the search process.