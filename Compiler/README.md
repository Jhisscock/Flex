Developer -- Jacob Hisscock
Project -- Checkpoint 8
Class -- Compiler Construction
Date -- 12/10/2020

Overview:
This program will take slic code, compile it, and generate matching gstal code.
Currently this works for variable declartion with integer and reals and assignment statements.
As well as expression evaluation, while loops, and counting loops with some exceptions.
As well as if/else statements and print statments.
Variables can also be declared as integer or real arrays.
There is no default value for a variable upon declaration, it is not allocated a space in memory until assignment.

Running Program:
In a terminal change directory to the Compiler folder on your machine.
Type make.
Then type ./a.exe < SlicProgramName.FileExtension.

Output:
This will generate a gstal file called c8.gstal.
Also it will print a statment to your terminal saying the file has been created successfully.

Not Working:
Array refrences using variables is not working and the mod operator has not been implemented either.
Also couting loops dont work if the to pointer is a varible but it does work for the from point.
Also some math expression if there is a statment enclosed with parentheses inside it doesn't work. i.e. 2 * 3 /(2 - 3)*2;
