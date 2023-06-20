#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 1000;

void merge(int a[n], int lb, int mid, int ub) {
    int i, j, k, b[n];
    i = lb;
    j = mid+1;
    k = lb;
    while(i<=mid && j<=ub) {
        if(a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        while(j<=ub) {
            b[k] = a[j];
            j++, k++;
        }
    }
    else {
        while(i<=mid) {
            b[k] = a[i];
            i++,k++;
        }
    }
    for(k=lb; k<=ub; k++) {
        a[k] = b[k];
    }
}

void mergesort(int a[n], int lb, int ub) {
    int mid;
    if(lb < ub) {
        mid = (lb + ub)/2;
        mergesort(a, lb, mid);
        mergesort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}

void main() {
    int a[n],i;
    clock_t start, end;
    double t;
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    for(i=0; i<n; i++) {
        // printf("Enter number: ");
        // scanf("%d", &a[i]);
        a[i] = rand();
    }

    start = clock();
    mergesort(a, 0, n-1);
    end = clock();

    t = ((double)(end - start));

    // for(i=0; i<n; i++) {
    //     printf("%d\t", a[i]);
    // }
    printf("The time taken is: %f", t);

}