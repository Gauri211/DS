#include<stdio.h>
#include<stdlib.h>

struct node *head;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(){

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void createList() {
    struct node *temp, *new;
    int num = 0;
    while(num == 0) {
        new = createnode();
        printf("Enter data of node: ");
        scanf("%d",&new -> data);
        if(head == NULL) {
            head = new;
            temp = new;
        }
        else {            
            temp -> next = new;
            new -> prev = temp;
            // new -> next = NULL;
            temp = new;
            
        }

        printf("Enter 0 to add more nodes: ");
        scanf("%d",&num);
    }
}

void display() {
    struct node *temp;
    temp = head;
    if(temp == NULL) {
        printf("Linked list not present");
    }
    else {
        while(temp -> next != NULL) {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d\t",temp -> data);
    }
}

void insertStart() {
    struct node *temp, *new;
    new = createnode();
    printf("Enter data: ");
    scanf("%d",&new -> data);
    if(head == NULL) {
        head = new;
    }
    else {
        new -> next = head;
        head -> prev = new;
        head = new;
    }
}

void insertEnd() {
    struct node *temp, *new;
    new = createnode();
    printf("Enter data: ");
    scanf("%d",&new -> data);
    temp = head;
    if(head == NULL) {
        head = new;
    }
    else {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new;
        new -> prev = temp;
    }
}

void insertAfter() {
    struct node *temp, *new, *ptr;
    int value;
    new = createnode();
    temp = head;
    printf("Enter data: ");
    scanf("%d",&new -> data);
    if(head == NULL) {
        head = new;
    }
    else {
        printf("Enter data after which node to be inserted: ");
        scanf("%d",&value);
        while(temp -> data != value && temp -> next != NULL) {
            temp = temp -> next;
        }
        ptr = temp -> next;
        new -> next = temp -> next;
        temp -> next = new;
        new -> prev = temp;
        ptr -> prev = new;
    }
}

void insertBefore() {
    struct node *temp, *new, *ptr;
    int value;
    new = createnode();
    temp = head;
    printf("Enter data: ");
    scanf("%d",&new -> data);
    if(head == NULL) {
        head = new;
    }
    else {
        printf("Enter data before which node to be inserted: ");
        scanf("%d",&value);
        while(temp -> data != value && temp -> next != NULL) {
            temp = temp -> next;
        }
        ptr = temp -> prev;
        ptr -> next = new;
        new -> prev = ptr;
        temp -> prev = new;
        new -> next = temp;       
    }
}

void delete() {
    struct node *temp, *new, *ptr;
    int value;
    temp = head;
    printf("Enter data of node which is to be deleted: ");
    scanf("%d",&value);
    if(head == NULL) {
        printf("Linked list not present");
    }
    //head node deletion
    else if(head -> data == value) {
        temp -> next -> prev = NULL;
        head = temp -> next;
        free(temp);
    }
    else {
        while(temp -> data != value && temp -> next != NULL) {
            temp = temp -> next; 
        }
        ptr = temp -> prev;
        ptr -> next = temp -> next;
        if(temp -> next == NULL) { //end node deletion
            free(temp);
        }
        else {
            temp -> next -> prev = ptr;
            free(temp);
        } 
    }
}

void main() {
    int option;
    int num;
    while(num == 0){
        printf("Enter case no to perform the operation: ");
        scanf("%d",&option);
        switch(option) {
            case 1: createList();
                break;
            case 2: insertStart();
                break;
            case 3: insertEnd();
                break;
            case 4: insertAfter();
                break;
            case 5: insertBefore();
                break;
            case 6: delete();
                break;
            case 7: display();
                break;
            default: printf("Invalid case!");
                break;    
        }
        printf("\nEnter 0 to continue: ");
        scanf("%d",&num);
    }
}