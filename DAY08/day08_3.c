/*Find max number of child processes that can be created on Linux using C program? Hint: use fork() in inﬁnite loop (wisely).*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{

    int ret ,s,i=1;
    while(1){

        ret=fork();
        if(ret==0){
            printf("child process %d ",getpid());
            _exit(0);
        }
        else if(ret==-1){
            printf("fork failed");
            break;
        }
        else{i++;
        printf("child count %d\n",i);}
    }
    for(int j=0;j<i;j++)
        wait(&s);

}