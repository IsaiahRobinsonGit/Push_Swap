# Push Swap: Sorting with Radix Sort

This repository contains my implementation of the **Push Swap** project from the 42 curriculum. The goal of this project is to sort a stack of integers using a limited set of stack operations, with a focus on algorithm efficiency and optimal use of resources.

---

## Features

- **Sorting Algorithm**: Implements the **Radix Sort** algorithm, adapted to work with two stacks (`a` and `b`), adhering to the constraints of the project.
- **Custom Operations**: Includes the following stack operations:
  - `sa`, `sb`, `ss`: Swap the top elements of one or both stacks.
  - `pa`, `pb`: Push the top element of one stack to the other.
  - `ra`, `rb`, `rr`: Rotate one or both stacks upwards.
  - `rra`, `rrb`, `rrr`: Reverse rotate one or both stacks.
- **Memory Management**: Ensures proper allocation and freeing of memory, verified with **Valgrind** to guarantee zero memory leaks.
- **Constraint Adherence**:
  - No functions exceed 25 lines.
  - A maximum of 5 functions per file.
  - Uses `while` loops instead of `for` loops, avoiding prohibited constructs like `switch`.
- **Debugging Tool**: Includes a **print stack function** to display the state of the stack before and after sorting for validation.

---

## How It Works

1. **Input Handling**:
   - The program accepts a stack of integers as input via command-line arguments.
   - Validates input to ensure only integers are provided, with no duplicates.

2. **Radix Sort**:
   - The stack of integers is divided into binary digits, sorted bit by bit (from least significant to most significant).
   - Numbers are pushed to stack `b` or kept in stack `a` based on their current bit value.
   - The process repeats for each bit, ultimately sorting the stack.

3. **Output**:
   - The program outputs the series of operations used to sort the stack.
   - Includes a debugging mode to visualize the state of stacks during execution.

---

## How to Use

### Clone the Repository
```bash
git clone https://github.com/IsaiahRobinsonGit/Push_Swap.git
```

### Compile the Program
Use the provided Makefile:
```bash
make all
```

### Run the Program
Run the executable with a set of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```

### Debugging (Optional)
Use the **print stack function** to observe the state of the stack before and after sorting.

---

## Example

Input:
```bash
./push_swap 4 67 3 87 23
```

Output:
```text
ra
ra
rb
ra
ra
pb
rra
...
```

---

## Learning Outcomes

Through this project, I:

- Implemented an efficient sorting algorithm.
- Developed clean, modular, and readable code by adhering to specific line and function limitations.
- Became better at debugging projects.

---
