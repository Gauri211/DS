#include<stdio.h>

#define MAX 10
int queue[MAX], front = -1, rear = -1;

void insert() {
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d",&num);
    if(rear == MAX-1 && front==0) {
        printf("\n OVERFLOW");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if(rear == MAX-1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = num;
}

void delete() {
    int val;
    val = queue[front];
    if(front == -1 && rear == -1) {
        printf("Underflow");
    }
    else if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else {
        front++;
    }
}

void display() {
    int i;
    if(front > rear) {
        for(i=front; i<MAX; i++) {
            printf("%d", queue[i]);
        }
        for(int i=0; i<= rear; i++) {
            printf("%d", queue[i]);
        }
    }
    else {
        for(int i=front; i<=rear; i++) {
            printf("%d", queue[i]);
        }
    }
}
void main() {

}