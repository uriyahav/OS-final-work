Instruction for running code:

Open the terminal in the folder where the source files are located.
In the terminal use the command 'make', this  command will compile the code file to an object file called set_policy.
Run this file using sudo with the policy and priority you want(only what you can , more explanation in the pdf file.
Policy can be one of the following:
•	OTHER = 0
•	FIFO = 1
•	RR = 2
•	IDLE = 5
•	DEADLINE = 6

The priority is an int you choose for the priority number.

For example if we want the RR policy with priority  0  :
Sudo ./set_policy 2 0 
