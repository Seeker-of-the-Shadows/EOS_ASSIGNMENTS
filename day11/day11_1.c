#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	int num1,num2, n1,n2, sum,s,res;
	int ret, arr1[2],arr2[2];
	printf("PARENT PROCESS STARTED !\n\n");
	sleep(1);
	ret=pipe(arr1);
	ret=pipe(arr2);
	printf("PARENT PROCESS\n\t waiting for data...\n");
	
	sleep(1);
	ret=fork();
	if(ret==0){
		printf("\nCHILD PROCESS STARTED !\n\n");
		close(arr1[0]);
		sleep(1);
		close(arr2[1]);
		printf("CHILD PROCESS \n\tEnter first number\t");
		scanf("%d",&num1);
		printf("CHILD PROCESS\n\tEnter second number\t");
		scanf("%d",&num2);
		
		printf("CHILD PROCESS\n\t writing to pipe...\n");
		sleep(1);
		write(arr1[1],&num1,sizeof(num1));
		write(arr1[1],&num2,sizeof(num2));
		printf("CHILD PROCESS\n\t write success !\n\n");

		sleep(1);
		read(arr2[0],&sum,sizeof(sum));
		printf("CHILD PROCESS\n\t Sum of %d , %d  is  %d\n",num1,num2,sum);
		sleep(1);
		close(arr1[1]);
		close(arr2[0]);
		printf("\nCHILD PROCESS COMPLETED !\n\n");

	}
	
	else{

		close(arr1[1]);
		close(arr2[0]);
		
		sleep(1);
		read(arr1[0],&n1,sizeof(n1));
		read(arr1[0],&n2,sizeof(n2));
		
		printf("PARENT PROCESS\n\t reading from pipe...\n");
		sleep(1);
		printf("PARENT PROCESS\n\t read success !\n\n");
		res=n1+n2;
		sleep(1);
		printf("PARENT PROCESS\n\t writing to pipe...\n");

		
		sleep(1);
		printf("PARENT PROCESS\n\t write success !\n\n");
		sleep(1);
		write(arr2[1],&res,sizeof(res));
		close(arr2[1]);
		close(arr1[0]);

	
	
		waitpid(-1,&s,0);
		
		printf("PARENT PROCESS COMPLETED !\n");

		sleep(1);
	}
	return 0;
}
