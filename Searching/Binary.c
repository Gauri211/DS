#include<stdio.h>
#include<conio.h>

void main() {
    int arr[10], n, i, l, r, mid, val,flag=0;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements of array in ascending order:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d",&val); 
    l = 0;
    r = n-1;
    while(l<=r) {
        mid = (l+r)/2 ;
        if(arr[mid]==val) {
            printf("Value found at index %d",mid);
            break;
        }
        else if(arr[mid]<val) {
            l = mid + 1;
        }
        else if(arr[mid]>val) {
            r = mid - 1;
        }
    }
    if(l>r) {
        printf("Element not found");
    }
}
