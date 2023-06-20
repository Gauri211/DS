#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    int pri;
    struct node *next;
};

struct node *head;

void insert() {
    struct node *new,*temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data and its priority: ");
    scanf("%d%d",&new -> data, &new -> pri);
    if(head == NULL || ((head -> pri) > (new -> pri))) {
        new -> next = head;
        head = new;
    }
    else {
        temp = head;
        while(temp -> next != NULL && (temp -> next -> pri  <= new -> pri)) {
            temp = temp -> next;
        }
            new  -> next = temp -> next;
            temp -> next =new;
    }
}

void delete() {
    struct node *temp;
    temp = head;
    if(head == NULL) {
        printf("Queue is empty");
    }
    else {
        printf("The data delete is %d and its priority is %d\n", head -> data, head -> pri);
        head = head -> next;
        free(temp);
    }
}

void display() {
    struct node *temp;
    temp = head;
    if(head == NULL) {
        printf("Queue is empty");
    }
    else {
        while(temp -> next != NULL) {
            printf("Data = %d and priority = %d\n", temp -> data, temp -> pri);
            temp = temp -> next;
        }
        printf("Data = %d and priority = %d\n", temp -> data, temp -> pri);
    }
}

void main() {
    int num = 1;
    while(num != 0) {
        printf("Enter operation: ");
        scanf("%d", &num);
        switch(num) {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            default: printf("Invalid case!");
                break;
        }
    }
}