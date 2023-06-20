#include<stdio.h>

void main() {
    int n,i,j,a[10],temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
            if(min != i) {
                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
    }
    
    printf("After sorting..\n");

    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }
}
