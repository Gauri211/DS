//Linear search
#include<stdio.h>
#include<conio.h>
void main() {
    int a[10], i, val, n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter number to search: ");
    scanf("%d",&val);
    for(i=0;i<n;i++) {
        if(a[i]==val) {
            printf("Number found at index %d",i);
            break; //to exit from loop
        }
    }
    if(i==n) {
            printf("Number not found");
        }
}