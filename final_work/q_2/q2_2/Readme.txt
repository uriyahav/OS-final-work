instruction for running Q2.2 code:

Open the terminal in the folder where the source files are located.
In the terminal use the command 'make', this  command will compile the code files to an object files called client , server.
Run the server fileusing the './' command , the pid of the server will be printed to the terminal.
In different terminal run the client with the  server pid and the num of signals you want to send to the server
For example:
1) ./client 2003 2 1000
2) ./client 2003 10 1.
We send from the client to the server that his pid is  2003 SIGINT(the number 2 above) 1000 times times.
We send from the client to the server that his pid is  2003 SIGUSR1(the number 10 above) 1 time.

For stopping the server use CTRL+Z
