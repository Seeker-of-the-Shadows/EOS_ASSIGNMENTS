#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


int main(){
    struct stat st;
    int fd1,fd2,ret ;
    void *src, *dest;
     clock_t t; 
    t = clock(); 

    //open the file 
    fd1 = open("/home/superuser/Downloads/src.jpg",O_RDWR);
    //get the file status
    ret = fstat(fd1,&st);
    printf("file size %ld\n",st.st_size);
    printf("file  time %ld\n",st.st_ctime);



    //memory map the file
    src= mmap(0,st.st_size,PROT_READ,MAP_SHARED,fd1,0);

    if(src == (void*)-1) {
		perror("mmap() failed");
		close(fd1);
		_exit(3);
	}
    
    
    

    //create a new file
    fd2 = open("/home/superuser/Downloads/dest.jpg",O_RDWR|O_CREAT,0666);

    //truncate the file to the size of the source file
    ftruncate(fd2,st.st_size);

    //memory map the file

    dest = mmap(0,st.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
    if(dest == (void*)-1) {
		perror("mmap() failed");
		close(fd2);
		_exit(3);
	}

    

    //copy the content of source file to the destination file

    memcpy(dest,src,st.st_size);
    printf("\nfile copied\n");
    ret = fstat(fd2,&st);
    printf("file size %ld\n",st.st_size);
    printf("file  time %ld\n",st.st_ctime);

    
    

    //unmap the files
    munmap(src,st.st_size);
    munmap(dest,st.st_size);

    //close the files
    close(fd1);
    close(fd2);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by copy is : %f seconds", time_taken);


    return 0;



    
}