#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

void insert() {
    struct node *new;
    new = (struct node *)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &new -> data);
    if(front == NULL && rear == NULL) {
        front = new;
        rear = new;
    }
    else {
        rear -> next = new;
        rear = new;
    }
}

void delete() {
    struct node *temp;
    int value;
    temp = front;
    value = front -> data;
    if(temp == NULL) {
        printf("Queue is empty");
    }
    else {
        front = front -> next;
        free(temp);
        printf("The value deleted is %d\n", value);
    }
}

void peek() {
    if(front == NULL) {
        printf("Queue is empty");
    }
    else {
        printf("The peek value is %d\n", front -> data);
    }
}
void display() {
    struct node *temp;
    temp = front;
    if(temp == NULL) {
        printf("Queue is empty");
    }
    else {
        while(temp != rear) {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d\n",temp -> data);
    }
}

void main() {
    int n = 1;
    while(n != 0) {
        printf("Enter operation: ");
        scanf("%d",&n);
        switch(n) {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: peek();
                break;
            case 4: display();
                break;
            default: printf("Invalid case!");
                break;
        }
    }
}