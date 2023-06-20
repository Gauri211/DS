#include<stdio.h>
#include<stdlib.h>

struct node *head;

struct node{
    int data;
    struct node *next;
};

struct node *createnode(){

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp -> next = NULL;
    return temp;
}

void createlist(){

    struct node *temp, *new;
    temp = head = NULL;

    int num = 9;
    while(num == 9){
        
        new = createnode();
        printf("Enter data: ");
        scanf("%d", &new->data);

        if(head == NULL){
            head = new;
            temp = new;
        }
        else{
            temp -> next = new;
            temp = new;
        }
        printf("Enter 9 to add more node: ");
        scanf("%d", &num);

    }
            new -> next = head;

    
}

void display(){
    struct node *temp;
    temp = head;

    if(temp == NULL) {
        printf("Linked list is not present");
    }
    else{
        while(temp -> next != head) {
            printf("%d\t",temp -> data);
            temp = temp -> next;
        }
        printf("%d\t",temp -> data);
    }
}

void insertbeg() {
    struct node *temp, *new;

    new = createnode();
    printf("Enter data to be entered at start ");
    scanf("%d", &new->data);
    temp = head;
    if(head == NULL){
        new = head;
        new -> next = head;
    }
    else {
        while(temp -> next != head) {
            temp = temp -> next;
        }
        new -> next = head;
        head = new;
        temp -> next = head;
    }
}


void insertend(){

    struct node *temp, *new;

    new = createnode();
    temp = head;

    printf("Enter data to be entered at end: ");
    scanf("%d", &new->data);

    if(head == NULL){
        head = new;
        new -> next = head;
    }
    else{
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = new;
        new -> next = head;
    }

}

void insertAfter() {
    struct node *temp, *new;
    int value;
    new = createnode();
    temp = head;


    printf("Enter data of new node: ");
    scanf("%d", &new->data);

    if(head == NULL){
        head = new;
        new -> next = head;
    }
    else {
        printf("Enter data of node after which new node to be inserted: ");
        scanf("%d",&value);
        while(temp -> data != value && temp -> next != head) {
            temp = temp -> next;
        }
        new -> next = temp -> next;
        temp -> next = new;
    }

}

void delete() {
    int value,n = 0;
    struct node *temp,*prev, *ptr;
    temp = head;
    prev = head;
    ptr = NULL;
    if(head == NULL) {
        printf("Linked list not present");
    } 
    else {
        printf("Enter data to delete the node: ");
        scanf("%d", &value);
        if(head -> data == value) { //head node deletion
            while(prev -> next != head) {
                prev = prev -> next;
            }
            head = head -> next;
            prev -> next = head;
            temp = NULL;       
        }   
        else {
            while(temp -> next -> data != value && temp -> next != head) {
                temp = temp -> next;
            }
            ptr = temp;
            temp = temp -> next;
            ptr -> next = temp -> next; 
            temp = NULL;
        }
    }  
}


void main(){
    int n;
    int ans = 9;
    while(ans==9) {
    printf("Enter case number to perform: ");
    scanf("%d",&n);
    switch(n) {
        case 1: createlist();
        break;
        case 2: insertbeg();
        break;
        case 3: insertend();
        break;
        case 4: insertAfter();
        break;
        case 5: delete();
        break;
        case 6: display();
        break;
        default: printf("Invalid case!");
        break;
    }
        printf("\nEnter 9 to continue: ");
        scanf("%d",&ans);
    }
}