# Makefiles

A makefile is a script which can compile your code for you based on a set of rules and dependencies. This has a few core benefits:
- Less typing for you
- Fewer mistakes!
- Only re-compiles if anything has changed
- can be auto-generated.

Makefiles are fairly generic - you need to change them a little bit for each application, but this is quite minimal for simple applications. In this one, you really only need to change the executable name.

Using a makefile is very simple, and most have the same 2 commands:
- `make`       : compile my code (technically 'run the first compile instruction')
- `make clean` : remove all the objects and executables created by `make`

So- `make` to compile, `make clean` to remove the compiled objects. It's good practice to `make clean` before you commit as this keeps everything tidy.

> **Danger:**
> Absolutely under no circumstances ever have a .c file in the OBJS or TARGET field as `make clean` will permanently and irreversibly remove them.

# Task

It's a quick one! Use the `make` and `make clean` command to compile the code, and have a read through the breakdown below to ensure you have some idea of what it's doing.

You can take the makefile and put it into another repository where you have C code to try it out on some other code if you want!

## Breaking it Down

### CC and CFLAGS

First things first, you set the compiler to use (CC) and the compiler flags which you want (CFLAGS).

CFLAGS may be changed at different points during the coding process. I usually start with -g -Wall -Werror, which translates to: I want to be able to use a debugger with this code, I want all the warnings enabled (wall) and I want those warnings to behave like errors (werror).

Wall and Werror are very useful; Wall enables warnings which can tell you if you are doing something which isn't exactly 'wrong' but might not work the way you expect. Werror makes these act as compiler errors, so your code won't compile unless these are fixed - which is a good idea when you want quality code (which you definitely do in my module :)).

### SRCS and OBJS

The sourcecode and objects come next. Sourcecode is important as this is where your program will be looking to find the .c files it needs to be able to compile your code.

You have two options for SRCS:
```bash
SRCS = $(wilcard *.c)
# or
SRCS = file1.c file2.c file3.c otherfolder/file4.c
```
The first will find every .c file in the current directory. The second will find the files you give the path to.

The absolute key thing is that **only one of the files it finds can contain a function called main()**. If you have more than one main() it will not be able to compile the program as it doesn't know which file will become the executable.

It is possible to write a makefile which can handle multiple mains (I have included an example in 'complicatedMakefile') when you need to be able to compile a wider array of executables.

In this makefile, OBJS is creating itself by saying 'replace all the .c files in SRCS with .o'.

## TARGET

This is the name of your executable - you will want to edit this to an appropriate executable name for your program.

## Everything below TARGET

Everything else is basically the script which does the compiling. Taking the settings provided above, it will compile the program by first compiling all the intermediate files (eg. file_io.c) into objects, and then finally putting these all together into your executable.

`clean` is defined at the bottom, and this is a simple `rm` line which will remove all the *object* files (not the original code) and the executable. You shouldn't need to edit this.

## Do I need to write one myself?

No.

You should be able to use the makefile provided to do pretty much anything you need to compile in this course. You can just copy it into any repository you need to use it in - the filename should be makefile or Makefile for it to work. You will need to make small edits but should find this is very easy.

Later in your working/university life you might learn how to generate makefiles using CMake or similar tools - this is how we normally do it, although manually writing makefiles may occasionally be needed for very high performance systems where you need complete control and want to change optimization settings.