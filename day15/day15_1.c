/*Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed.
Hint: Pass array to thread function (via arg4 of pthread_create()).*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10

void *selection_sort(void *arg)
{
    int *arr = (int *)arg;
    int i, j, min_idx, temp;
    for (i = 0; i < MAX-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < MAX; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;


    }
    return NULL;

}

int main()
{
    
    int ret,arr[MAX] = {64, 34, 25, 12, 22, 11, 90};
    pthread_t tid;
    int i;
    ret=pthread_create(&tid, NULL, selection_sort, (void *)arr);
    printf("main thread waiting for t1 thread...\n");
    pthread_join(tid, NULL);
    printf("Sorted array: \n");
    for (i = 0; i < MAX; i++)
        printf("%d ", arr[i]);

    return 0;


}