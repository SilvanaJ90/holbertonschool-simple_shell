# SIMPLE SHELL IN C

## What is a Shell

Shell is a program that takes the command inputs written from the the user’s keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command inputs from the user are correct.
So, in general, a Shell is a user interface to use the services of a computer. It can be a command-line interface –the one we will build- or graphical user interface, like regular software such as Windows Office or Adobe suites.

<img src="https://miro.medium.com/max/700/0*-OOMpchdZWQZr4zw" />

[![asciicast](https://asciinema.org/a/sqwiCAV62b0tc9mUSQ2vvnUwY.svg)](https://asciinema.org/a/sqwiCAV62b0tc9mUSQ2vvnUwY)

## SIMPLE_SHELL

### NAME
    sh — shell, the standard command language interpreter

## SYNOPSIS
    #include <stdio.h>
        char _prompt(void);
        char *_getline(ssize_t *characterRead);

    #include <string.h>
        char **_strtok(char *line, ssize_t characterRead);
    #include <unistd.h>
        int _execute(char **tokens, int status);

## DESCRIPTION

Shell is a program that takes the command inputs written from the the user’s
keyboard and passes them to the machine to execute them through the kernel.
It also verifies if the command inputs from the user are correct. So,
in general, a Shell is a user interface to use the services of a computer.
It can be a command-line interface –the one we will build- or graphical user
interface, like regular software such as Windows Office or Adobe suites.


## EXAMPLE

## COMPILATION

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## TESTING

Your shell should work like this in interactive mode:

    $   ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

But also in non-interactive mode:
    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $

### This file lists all individuals having contributed content to the repository.
 
Giovanni Pérez <5187@holbertonstudents.com>
Silvana Jaramillo <5211@holbertonstudents.com>
