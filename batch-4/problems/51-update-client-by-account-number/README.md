# Update Client By Account Number

## Methods

### Method 1 & 2 (Unified Logic)
Both solutions handle the update process by loading all clients into a vector, searching for the target record by account number, and then updating its fields in memory. After modification, the vector is saved back to the file to reflect the changes.

## Key Difference
**Method 1** passes the entire client object (`sClient`) to a separate function (`ChangeData`) to modify it. **Method 2** simplifies this by updating the client directly within the loop inside the main update function using a record-building function.

## Note
Updating records in a text file is a "Load-Modify-Save" operation. This ensures that only the intended record is changed while preserving the integrity of the rest of the data.