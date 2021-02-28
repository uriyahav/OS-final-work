
Instruction for running Q2.1 code:

Open the terminal in the folder where the source files are located.
In the terminal use the command 'make', this  command will compile the code file to object file called check_pid.
Run this file with the process id  you want.
The output for this run will be one of the following options:
If EPERM, Process <pid> does not exist.
If ESRCH, Process <pid> does not exist.
If kill is successful, Process <pid> exists.
Running example : check_pid 2003
Process 2003 exists
