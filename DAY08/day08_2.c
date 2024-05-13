/*From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{   int r1,r2,r3,s1,s2,s3;
    
      
        
        r1=fork();
        if(r1==0)
        { 
        
        
        r2=fork();
        if(r2==0)
		{ 
        
        
        r3=fork();
		if(r3==0)
		{  
            for (int count= 1; count <= 5; count++)
        {
           printf("child process D %d count %d \n",getpid(),count);
            sleep(1);
            }_exit(0);
            
        }

           
            for (int count= 1; count <= 5; count++)
        {
           printf("child process C %d count %d \n",getpid(),count);
            sleep(1);
            }
            waitpid(r3,&s3,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s3));
            _exit(0);
            }
            

            for (int count= 1; count <= 5; count++){
           printf("child process B %d count %d \n",getpid(),count);
            sleep(1);
            }
            waitpid(r2,&s2,0);
            
            printf("child exit -> %d \n ", WEXITSTATUS(s2));
            _exit(0);
            }
            for (int count= 1; count <= 5; count++){
           printf("PARENT  process A %d count %d \n",getpid(),count);
            sleep(1);}
            waitpid(r1,&s1,0);
            
            printf("child exit -> %d \n ", WEXITSTATUS(s1));
            _exit(0);
            return 0;
            }
            

	
    
            



