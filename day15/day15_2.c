/*2. Create a thread to sort given array of "n" integers using bubble sort. Main thread should print the result after sorting is completed.
Hint: struct array { int *arr; int size; }
Pass struct address to thread function (via arg4 of pthread_create()).*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define max 10

struct array {
    int *arr;
    int size;   

};

void  bubble_sort(int *arr, int n) {
    int i, j;
    printf("sorting... \n");
    sleep(2);
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    }

    void *bubble_sort_thread(void *arg) {
        struct array *data = (struct array *)arg;
        bubble_sort(data->arr, data->size);
        pthread_exit(NULL);

    }

    int main() {
        
        int n, i, ret;
        n=max;
        int arr[max] = {64, 34, 25, 12, 22, 11, 90};
        // printf("Enter number of elements: ");
        // scanf("%d", &n);

        // int arr[n];
        // printf("Enter elements: ");
        // for (i = 0; i < n; i++) {
        //     scanf("%d", &arr[i]);
        // }

        struct array st_arr = { arr, n };

        pthread_t tid;
        ret=pthread_create(&tid, NULL, bubble_sort_thread, (void *)&st_arr);

         if(ret < 0) {
		perror("pthread_create() failed");
		_exit(0);
	}
        printf("New POSIX Thread ID: %lu\n", tid);

        printf("main thread waiting for new thread...\n");

        sleep(1);


        
        pthread_join(tid, NULL);

        printf("Sorted array: ");
        for (i = 0; i < n; i++) {
            
            printf("%d ", arr[i]);

        }

        printf("\n");

        return 0;


    }

