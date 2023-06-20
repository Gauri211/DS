#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 10000;

void quicksort(int a[n], int lb, int ub) {
    int temp,pivot,start,end;
    if(lb < ub) {
    pivot = a[lb];
    start = lb;
    end = ub;
    while(start < end) {
        while(a[start] <= pivot) {
            start++;
        }
        while(a[end] > pivot) {
            end--;
        }
        if(start < end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
        quicksort(a, lb, end-1);
        quicksort(a, end+1, ub);
    }
}

void main() {
    int i,a[n];
    clock_t start, end;
    double t;
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    for(i=0; i<n; i++) {
        a[i] = rand();
    }
    start = clock();
        quicksort(a, 0, n-1);
    end = clock();
    t = (double)(end - start);
    printf("The time taken is: %f", t);
    // for(i=0; i<n; i++) {
    //     printf("%d\t", a[i]);
    // }
}