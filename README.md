# Pipex

Pipex is a project in the 42 school curriculum, designed to introduce students to Unix pipes and process manipulation. The goal of this project is to create a program that simulates the behavior of the shell command `"< file1 cmd1 | cmd2 > file2"` using the `pipe`, `fork`, and `execve` system calls.

## Introduction

In this project, you will implement a program called `pipex` that takes four arguments:

./pipex file1 cmd1 cmd2 file2


The program should read the input from `file1`, execute `cmd1` with this input as standard input, then execute `cmd2` with the output of `cmd1` as standard input, and finally write the output of `cmd2` to `file2`.

## Features

- Input/output redirection using files.
- Execution of shell commands using `execve`.
- Process creation and management using `fork`.
- Inter-process communication using Unix pipes.

## Installation

To compile the Pipex program, run the following command:

```bash
make
```
This will generate an executable file named pipex.

## Usage
To use the Pipex program, run it with the following arguments:

```bash
./pipex file1 cmd1 cmd2 file2
```
Replace file1, cmd1, cmd2, and file2 with the appropriate filenames and shell commands.

## Example
Here's an example of how to use Pipex to execute the shell command "< file1 cmd1 | cmd2 > file2":

```bash
./pipex infile "ls -l" "wc -l" outfile
```
This will list the files in the current directory, count the number of lines in the output, and write the result to outfile.

## Contributing
Contributions are welcome! If you want to improve the project, please submit a pull request. Make sure to follow the contribution guidelines.

## Contact
If you have any questions or suggestions, feel free to contact me via email.

Thank you for using Pipex!

