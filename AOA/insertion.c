#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 10000;

void insertion(int n, int arr[n]) {
    for(int i=1; i<n; i++) {
        int j = i - 1;
        int temp = arr[i];
        while(j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void main() {
    int arr[n];
    clock_t start, end;
    double t;
    
    //Best case
    for(int i=0; i<n; i++) {
        arr[i] = i;
    }
    start=clock();
        insertion(n, arr);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken for Best case: %f", t);
    
    //Worst case
    for(int i=n; i>0; i--) {
        arr[i] = i;
    }
    start=clock();
        insertion(n, arr);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken for Worst case: %f", t);
    
    //Average case
    for(int i=0; i<n; i++) {
        arr[i] = rand();
    }
    start=clock();
        insertion(n, arr);
    end=clock();
    t = ((double)(end-start));
    printf("\nTime taken for Average case: %f", t);
    // printf("After sorting...\n");
    // for(int i=0; i<n; i++) {
    //     printf("%d ", arr[i]);
    // }
}