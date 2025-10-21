# Veclab Program
The veclab program performs vector operations on vectors stored in dynamic memory. 
The program can import and export saved vectors as csv files.

## Build:
Build the program with the included Makefile:\
$ make

## Run:
Run the program with the veclab.c file. Include -h to display supported commands.\
$ ./veclab -h

## Supported Commands
Vector operation commands supported:

>help                  | Display commands list\
  list                   | List all vectors\
  load <filename.csv>    | Load vectors from a csv file\
  save <filename.csv>    | Save vectors to a csv file\
  name = x y z           | Create or change vector\
  name + name            | Add two vectors\
  name - name            | Subtract two vectors\
  name * scalar          | Multiply vector by scalar\
  name . name            | Dot product of two vectors\
  name x name            | Cross product of two vectors\
  name = operation       | Assignment after operation\
  clear                  | Clear all vectors\
  quit/exit              | Exit the program

## Dynamic Memory
Dynamic memory is used to store unlimited vectors, found in the vectarray.c allocate() function.