# VG101 Jigang RC4 - Unix-like, compilation and C Programming

## Basic UNIX-style Commands

### Command Line / Terminal

In Windows, we can open our command line by inputting `cmd` or `powershell` in the file explorer. In MAC, we can open command line in Terminal application. `powershell` and MAC shell have most of UNIX-style commands. Knowing basic shell command can improve your developing efficiency by a great scale.

### Basic Commands

1. cd

   Change directory. `cd ~` changes to personal directory,  `cd /` changes to root directory and `cd ..` changes to previous directory.

2. ls

   List all the files and subdirectories under this directory. `ls PATH` lists its children if it is a directory, `ls FILENAME` gives output only when FILENAME exists and `ls -a` lists hidden directories.

3. cat

   Output the content of the file.

4. gcc

   GNU C Compiler, the official compiler we use in VG101.

## C Compilation Process & How to Compile a C Program Using GCC

### Compilation Process

1. Pre-process

   ```shell
   gcc -E INPUT -o OUTPUT
   ```

2. Compiling

   ```shell
   gcc -S INPUT -o OUTPUT
   ```

3. Assembling

   ```shell
   gcc -c INPUT -o OUTPUT
   ```

4. Linking

### Compile C Program

1. Compile ONE C code without extra libraries (except std libraries).

   ```shell
   gcc INPUT -o OUTPUT
   ```

2. Compile ONE C code with MATH library.

   ```shell
   gcc INPUT -o OUTPUT -lm
   ```

3. Compile SEVERAL C codes and link them together

   ```shell
   gcc INPUT1 INPUT2 -o OUTPUT
   ```

4. Compile arguments we use in VG101

   ```shell
   gcc -O2 -Wall -Wextra -Werror -pedantic -Wno-unused-result -std=c99 -o OUTPUT INPUTS -lm
   ```

5. Use CMAKE (not required)

## C Syntax

### Type Declaration

1. C is a strong-type language, so any variable should be declared explicitly with a type and the type of a variable is constant.

2. Syntax:

   ```C
   typename var1, var2, ...;
   ```

3. Type decoration (such as *, &, etc) can only decorate the following variable.

### Block and Scope

1. In C++, {} denotes a block
2. Local variable declared in a block will be destroyed when the block ends.

### Control Statements

1. `if` statement

   Syntax:

   ``` C
   if (condition) statement;
   ```

   statement can also be replaced by a block.

2. `switch` statement

   Syntax: 

   ```C
   switch (var) {
       case a:
           statement;
           break;
       case b:
           statement;
           break;
       default:
           statement;
   }
   ```

   `break` is necessary or after running 'a' it will automatically run 'b'.

   Notice that statement is not contained in a block, so variable declaration would be troublesome.

### Loop

1. `for` loop
   Syntax:

   ```C
   for (initialzation;end_condition;step) statement;
   ```

   Think:

   ```C
   for (int i = 1; i < 8; i *= 2) statement;
   ```

   will run statement for ? times?

2. `while` loop

   Syntax:

   ```C
   while (condition) statement;
   ```

   or

   ```C
   do statement while (condition);
   ```

   What's the difference?

### Function

1. General syntax

   ```C
   return_type fun(args...) {
       statements;
       return some_value;
   }
   ```

   if there is no return value,

   ```C
   void fun(args) {
       statements;
   }
   ```

2. Separation of declaration

   Functions should be declared before they're used. We could use

   ```C
   return_value fun(args...);
   ```

   to declare a dummy function and write implementations anywhere that is linked to the program.

## JOJ

### About Online Judge

There are many online judging platforms, such as CodeForces, Leetcode, etc. In JI, we provide our own OJ platform: JOJ.

### How to Join

Here is the invitation code for JOJ 
Link: https://joj.sjtu.edu.cn/d/vg101_fall_2020_jigang/join
Code: JIGANG101