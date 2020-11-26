# simple_shell project

This projects aims to create a simple shell, from scratch, with as much features as possible.

The shell is a program that reads lines from the standard input (either from a file piped into it or from user typed terminal commands), interprets them, and generally executes other commands.
Simple_shell can be used in two different ways, either interactive or non-interactive. Interactive mode launches the shell in a terminal, displays a prompt, and waits for the user to enter the desired commands. Non-interactive mode lets the user pipe a script file (that includes one command per line) through to the shell executable (see examples below).

## How to use it

1. Clone this repository

```bash
 $ git clone https://github.com/ThibaudP/simple_shell.git
```

2. Compile all files to get executable file

```bash
 $ gcc *.c -o hsh
```

3. Execute

```bash
 $ ./hsh
```

## Examples

### Interactive mode

Interactive mode lets the user input commands through the terminal.
To exit simple_shell, either press ```CTRL + D``` or use the ```$ exit``` built-in command.

After installation, execute the command below to launch simple_shell

```bash
 $ ./hsh
```

The single ``$ `` prompt will be displayed.
```bash
 $:
```

```bash
 $ ./hsh
 $ echo "hello world"
 hello world
 $ 
```

### Non-interactive mode

Non-interactive mode lets you redirect any line (either echo'ed or printed from a file) to the standard input of simple_shell, execute those commands (line by line in case of multiple commands), then exit the shell.

```bash
 $ echo "the command you want to run" | ./hsh
```

```bash
 $ echo "pwd" | ./hsh
/home/foo/bar
```


```bash
 $ echo "pwd" | ./hsh
/home/foo/bar
 $ cat testfile
 cd /tmp
 touch toto
 ls -l
 $ cat testfile | ./hsh
 total 0
 -rw-rw-r-- 1 vagrant vagrant 0 Nov 25 13:35 toto
```

## Task list

Below is a list of the required tasks and their corresponding features.

### Mandatory tasks

- [x] Task 0 - Write README, man & AUTHORS files
- [x] Task 1 - Write beautiful code that passes the Betty checks
- [x] Task 2 - Display prompt, handle simple single commands without arguments, handle errors & EOF condition
- [x] Task 3 - Handle commands with arguments
- [x] Task 4 - Handle PATH
- [x] Task 5 - Implement the ``exit`` built-in
- [x] Task 6 - Implement the ``env`` built-in
- [x] Task 7 - Blog post "What happens when you type ``ls -l`` in the shell"

### Advanced tasks

- [x] Task 8 - Contribute to a cohort-wide test suite for this project
- [ ] Task 9 - Rewrite ``getline();`` (using a buffer & static variables)
- [x] Task 10 - Rewrite ``strtok();``
- [x] Task 11 - Handle arguments for ``exit``
- [x] Task 12 - Handle ``Ctrl+C`` (shell shouldn't quit after ^C input)
- [x] Task 13 - Implement the ``setenv`` and ``unsetenv`` built-ins
- [x] Task 14 - Implement the ``cd`` built-in
- [ ] Task 15 - Handle the commands separator ``;``
- [ ] Task 16 - Handle the ``&&`` and ``||`` shell logical separators
- [ ] Task 17 - Implement the ``alias`` built-in
- [ ] Task 18 - Handle variables replacement, ``$?`` and ``$$``
- [x] Task 19 - Handle comments (``#``)
- [x] Task 20 - Handle the ``help`` built-in
- [ ] Task 21 - Implement the history (without arguments)
- [ ] Task 22 - The shell can take a file as input (e.g. ``simple_shell [filename])``


## Authors
[Arthur Mayer](https://www.github.com/Zarathustra) & [Thibaud Poncin](http://www.github.com/ThibaudP)
