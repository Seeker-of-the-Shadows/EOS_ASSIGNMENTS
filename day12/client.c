/*The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
process print the result.*/

#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>

// client
int main() {
	int fdw,fdr,a,b,sum;
	
	fdw = open("/home/superuser/desd_client", O_WRONLY);
	
		printf("Enter numbers for addition\n");
		printf("A -> ");
        scanf("%d",&a);
        printf("B -> ");
        scanf("%d",&b);

		write(fdw, &a, sizeof(int));//write a to server process

		write(fdw, &b, sizeof(int));//write b to server process

	fdr= open("/home/superuser/desd_server", O_RDONLY);
		printf("\nwaiting for data...\n\n");

		read(fdr,&sum, sizeof(int));//read the result from server process
		printf("SUM -> %d\n", sum);

	

	close(fdw);
	close(fdr);
	return 0;
}
