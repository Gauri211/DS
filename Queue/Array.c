#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert();
int delete();
int peek();
void display();

//Inserting an element in Queue
void insert() {
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d",&num);
    if(rear == MAX-1) {
        printf("\n OVERFLOW");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = num;
}

//Deleting an element from queue
int delete() {
    int val;
    if(front == -1 || front > rear) {
        printf("\n UNDERFLOW");
        return -1;
    }
    else {
        val = queue[front];
        front++;
        if(front > rear) {
            front = rear = -1;
        }
        return val;
    }
}

//Peek operation
int peek() {
    if(front == -1 || front > rear) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else {
        return queue[front];
    }
}

//Display Queue
void display() {
    int i;
    printf("\n");
    if(front == -1 || front > rear) {
        printf("\n QUEUE IS EMPTY");
    }
    else {
        for(i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
    }
}

void main() {
    int n, val;
    do {
            printf("\nEnter n: ");
            scanf("%d",&n);
        switch (n)
        {
        case 1: insert();
            break;
        case 2: 
            val = delete();
            if(val != -1) {
                printf("The number deleted is %d",val);
            }
            break;
        case 3: 
            val = peek();
            if(val != -1) {
                printf("The first number in queue is %d",val);
            }
            break;
        case 4: display();
            break;
        default: printf("Invalid operation!");
            break;
        }
    }while(n != 0);
}