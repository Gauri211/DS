#include<stdio.h>

void main() {
    int n,i,j,a[10],temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }
    for(i=1; i<n; i++) {
        temp = a[i];
        j = i - 1;
        while(j>=0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

    printf("After sorting..\n");

    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }
}

//Time complexity:
//Worst case O(n^2)
//Best case O(n)