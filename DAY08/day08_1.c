/*From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes
to complete and clean all of them. Hint: use loop to fork() multiple child processes.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{   int ret , i , s;
    for(i=0;i<5;i++)
    {   ret=fork();
        if(ret==0)
        {    for (int count= 1; count <= 5; count++)
        {
           printf("child process %d count %d \n",getpid(),count);
           sleep(1);
        }
        
            
            exit(i);
        }
        }
	
     for(i=0;i<5;i++)
     {   waitpid(-1,&s,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s));
            }
         
            return 0;


}
