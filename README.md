# Hash table implementation

This project implements a basic hash table with separate chaining for collision resolution and integrates sorting functionalities. It includes operations for inserting and removing elements in the hash table, merging two hash tables, and sorting the merged table. The project demonstrates dynamic memory allocation, hash functions, and sorting algorithms in C.

## Features

- **Hash Table Initialization:** Initializes hash tables with a specified size.
- **Hash Functions:** Implements two hash functions for distributing keys.
- **Insert Operation:** Inserts elements into the hash tables with collision handling.
- **Remove Operation:** Removes elements from the hash tables.
- **Merge Operation:** Merges two hash tables into a larger auxiliary table.
- **Sorting:** Sorts the elements of the merged table.
- **Print Function:** Prints the contents of the hash table.
- **Memory Management:** Properly manages memory allocation and deallocation.

## File Structure

- `main.c`: Contains the main function that drives the program.
- `sort.c`: Implements the sorting algorithm.
- `hash.c`: Implements hash table operations.

## Usage

1. Compilation: Compile the program using make.

```sh
make
```

2. Execution: Run the compiled program.

```sh
./hash_sort_program
```

3. Input: The program reads commands from standard input.

- `i <value>`: Insert <value> into the hash table.
- `r <value>`: Remove <value> from the hash table.
- The program ends when EOF (End of File) is reached.

## Example

```sh
./hash_sort_program
i 10
i 20
r 10

i 30
```

## Functions

### Hash Table Functions (hash.c)
- hash_init(int size): Initializes a hash table of given size.
- hash_insert(item_t** t1, item_t** t2, int value): Inserts a value into the hash table.
- hash_remove(item_t** t1, item_t** t2, int value): Removes a value from the hash table.
- hash_merge(item_t** t1, item_t** t2, item_t** aux): Merges two hash tables into an auxiliary table.
- hash_print(item_t** aux): Prints the contents of the hash table.
- hash_delete(item_t** t): Frees memory allocated for the hash table.
- h1(int value): First hash function.
- h2(int value): Second hash function.

### Sorting Functions (sort.c)
- sort(item_t** vet, int a, int b): Sorts an array using recursive insertion sort.
- insert(item_t** vet, int a, int b): Helper function for insertion sort.
- search(int x, item_t** vet, int a, int b): Searches for the appropriate position in the array.
- shift(item_t** vet, int a, int b): Shifts elements in the array.

## Memory Management

The program uses malloc for dynamic memory allocation and ensures proper deallocation using free to avoid memory leaks.
