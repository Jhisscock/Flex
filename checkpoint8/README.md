Developer -- Jacob Hisscock
Project -- Checkpoint 8
Class -- Compiler Construction
Date -- 12/8/2020

Overview:
This program will take slic code, compile it, and generate matching gstal code.
Currently this works for variable declartion with integer and reals and assignment statements.
As well as expression evaluation and while loops.
As well as if/else statements and print statments.
Variables can also be declared as integer or real arrays.
There is no default value for a variable upon declaration, it is not allocated a space in memory until assignment.

Running Program:
In a terminal change directory to the checkpoint 6 folder on your machine.
Type make.
Then type ./a.exe < SlicProgramName.FileExtension.

Errors:
If an error occurs when generating the gstal code a statment will be printed to the terminal with the variable it errored at.
If an error occurs during parsing a statment will print saying that parsing failed.
An error will occur when a variable name not yet declared is trying to be accessed.

Output:
This will generate a gstal file called c8.gstal.
Also it will print a statment to your terminal saying the file has been created successfully.

Not Working:
Curretly couting statments are not implemented fully as well as the read instuction.
Also nested if statments and while loops cause issues sometimes the jump instructions will be wrong.

Note:
You can access a non-array variable's value by using varname[0]. 
This is because it will acess the memory address at postion 0 of the variable which is equal to its assigned value in memory.