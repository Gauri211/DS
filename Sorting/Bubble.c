#include<stdio.h>

void main() {
    int n,i,j,a[10],temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n-i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("After sorting..\n");

    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }
}