Instruction for running Q4 code:

Open the terminal in the folder where the source files are located.
In the terminal use the command 'make', this  command will compile the code file to object file called dir_traversal.
Run this file with the name of directory  you want to start 'travel' in.
the output of the program is : symbol- letter that symbolized the type (directory file etc) , inode number , name of the file/directory.

Example:
Make directory and files  for travel example

$ mkdir dir
$ touch dir/a dir/b
$ ln -s a dir/sl ←- later ignored from the output
$ mkdir dir/sub
$ touch dir/sub/x

we run the code on the directory dir created above

$ ./dir_traversal dir
The output:
D 2327983 dir
F 2327984 a
F 2327985 b
D 2327988 sub
F 2327989 x
