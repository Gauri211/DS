#include<stdio.h>

#define MAX 10
int queue[MAX], frontA = -1, rearA = -1, frontB = MAX, rearB = MAX;

void insertA() {
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d",&num);
    if(rearA == rearB-1) {
        printf("\n OVERFLOW");
    }
    else if(frontA == -1 && rearA == -1) {
        frontA = rearA = 0;
    }
    else {
        rearA++;
    }
    queue[rearA] = num;
}

void deleteA() {
    int val;
    if(frontA == -1) {
        printf("Underflow");
    }
    else {
        val = queue[frontA];
        frontA++;
        if(frontA > rearA) {
            frontA = rearA = -1;
        }
        printf("The number deleted is %d",val);
    }
}

void displayA() {
    if(frontA == -1) {
        printf("Underflow");
    }
    else {
        for(int i=frontA; i<=rearA; i++) {
            printf("%d\t", queue[i]);
        }
    }
}

void insertB() {
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d",&num);
    if(rearB == rearA+1) {
        printf("\n OVERFLOW");
    }
    else if(frontB == MAX && rearB == MAX) {
        frontB = rearB = MAX-1;
    }
    else {
        rearB--;
    }
    queue[rearB] = num;
}

void deleteB() {
    int val;
    if(frontB == MAX) {
        printf("Underflow");
    }
    else {
        val = queue[frontB];
        frontB--;
        if(frontB < rearB) {
            frontB = rearB = MAX;
        }
        printf("The number deleted is %d",val);
    }
}

void displayB() {
    if(frontB == MAX) {
        printf("Underflow");
    }
    else {
        for(int i=frontB; i>=rearB; i--) {
            printf("%d\t", queue[i]);
        }
    }
}

void main() {
    int n=1;
    while(n != 0) {
        printf("\nEnter operation: ");
        scanf("%d", &n);
        switch(n) {
            case 1: insertA();
                break;
            case 2: insertB();
                break;
            case 3: deleteA();
                break;
            case 4: deleteB();
                break;
            case 5: displayA();
                break;
            case 6: displayB();
                break;
            default: printf("Invalid case!");
                break;
        }
    }
}