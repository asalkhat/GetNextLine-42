*This activity has been created as part of the 42 curriculum by asalkhat.*

# Get Next Line

## Description

Get Next Line (GNL) is a project from the 42 curriculum written in C. The goal is to create a function that reads from a file descriptor and returns one line at a time.

The function returns a line including the newline character (`\n`) when present. If the last line does not end with a newline, it returns the remaining text. When there is no more content to read or an error occurs, it returns `NULL`.

This project helps develop an understanding of file descriptors, the `read()` system call, static variables, dynamic memory allocation, and string manipulation.

## Instructions

### Project Files

- `get_next_line.c` — Contains the main function and the logic for reading and extracting lines.
- `get_next_line_utils.c` — Contains helper functions for string length, joining strings, and extracting substrings.
- `get_next_line.h` — Contains function prototypes, required headers, and the default buffer size.

### Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Replace `main.c` with your test file if it has a different name.

### Execution

Run the program:

```bash
./gnl
```

The test program should open a file, call `get_next_line()` repeatedly, print each returned line, and free the memory allocated for each line.

The `BUFFER_SIZE` determines how many bytes are requested in each call to `read()`. You can change it during compilation to test different buffer sizes.

### Function Prototype

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.
- **Return value:** The next line as a dynamically allocated string, or `NULL` when no line remains or an error occurs.

## Algorithm

The algorithm uses a saved string to preserve characters read from the file that have not yet been returned to the caller.

### 1. Read and save

The function allocates a temporary buffer and uses `read()` to read up to `BUFFER_SIZE` bytes from the file descriptor.

The newly read characters are joined to the saved string. Reading continues until a newline is found or the end of the file is reached.

### 2. Extract the line

The function searches the saved string for the first newline character.

If a newline is found, it creates a new string containing all characters up to and including that newline. If no newline exists, it returns the remaining characters as the final line.

### 3. Update the saved string

After extracting the line, the function saves the characters following the newline for the next call.

The old saved string is freed to prevent unnecessary memory use. If no characters remain, the saved string becomes `NULL`.

### 4. Return the line

The function returns the extracted line. When called again, it continues using the saved characters before reading more data from the file.

### Why This Algorithm?

Reading in chunks instead of one character at a time reduces the number of calls to `read()`. Using a saved string prevents characters belonging to the next line from being lost when one read contains multiple lines.

Dynamic memory allocation allows the function to handle lines of different lengths instead of requiring a fixed-size line buffer.

## Resources

### YouTube

- [YouTube tutorials on Unix file descriptors and pipes](https://www.youtube.com/results?search_query=Unix+file+descriptors+and+pipes+tutorial)

### GeeksforGeeks

- [Input-output system calls in C](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

### Manual Pages

- [`read()`](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open()`](https://man7.org/linux/man-pages/man2/open.2.html)
- [`malloc()` and `free()`](https://man7.org/linux/man-pages/man3/malloc.3.html)

### University Notes

1. [Virginia Tech — Unix File Descriptors and Pipes](https://courses.cs.vt.edu/cs3214/spring2026/lecturesli/fdpipes.pdf)
2. [University of California, Santa Barbara — System Calls Lecture Notes](https://sites.cs.ucsb.edu/~rich/class/cs170/notes/SystemCalls/index.html)

These resources explain file descriptors, input/output system calls, pipes, and how programs interact with the operating system.

### AI Usage

AI tools were used as a learning aid during this project to explain file descriptors, the `read()` system call, static variables, dynamic memory allocation, and string manipulation.

AI was also used to help understand the algorithm step by step, identify potential errors, explain compilation issues, review code structure, and prepare the project documentation. The explanations supported the learning and debugging process throughout the activity.