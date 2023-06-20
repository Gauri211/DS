#include<stdio.h>
#include<stdlib.h>
//deaclaration
struct node {            
    int data;
    struct node *next;   //*name - pointer variables
};
struct node *head; //Globally declaring head pointer variable

//Creating node
struct node *createnode() {
    struct node *temp;  
    temp = (struct node *)malloc(sizeof (struct node)); //typecasting to address node
    temp -> next = NULL; //One temp node is created with address as null
    return temp;
};
//Creating list
void createlist() {
    struct node *temp,*newnode;
    head = temp = NULL;
    int ans = 9;
    while(ans==9) {
        newnode = createnode();
        printf("Enter data: ");
        scanf("%d",&newnode -> data);
        if(head==NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Enter 9 to add more nodes: ");
        scanf("%d",&ans);
    }
}
//Display list
void display() {
    struct node *temp;
    temp = head;
    if(temp == NULL) {
        printf("Linked list not present");
    }
    else {
        while(temp!=NULL) {
            printf("%d\n",temp -> data);
            temp = temp -> next;
        }
    }
}

//Insert node at beginning
void insertbeg() {
    struct node *temp,*newnode;
    newnode = createnode();
    printf("Enter data: ");
    scanf("%d",&newnode -> data);
    if(head==NULL) {
        newnode = head;
    }
    else {
        newnode -> next = head;
        head = newnode;
    }
}

//Insert node at end
void insertend() {
    struct node *temp,*newnode;
    newnode = createnode();
    printf("Enter data: ");
    scanf("%d",&newnode -> data);
    temp = head;
    if(head==NULL) {
        newnode = head;
    }
    else {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

//Insert node after a particular node 
void insertafter() {
    int value;
    struct node *temp,*newnode;
    newnode = createnode();
    printf("Enter data: ");
    scanf("%d",&newnode -> data);
    temp = head;
    if(head==NULL) {
        newnode = head;
    }
    else {
        printf("Enter data after which node to be inserted: ");
        scanf("%d",&value);
        while(temp -> data != value && temp -> next != NULL) {
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

//Deleting node
void delete() {
    int value;
    struct node *temp,*prev;
    printf("Enter data to delete the node: ");
    scanf("%d", &value);
    temp = head;
    prev = NULL;
    
    while(temp != NULL) {
        if(temp -> data == value) {
            if(prev == NULL) {
                head = head -> next;
                temp -> next = NULL;
                temp = NULL;               
            }
            else {
                
                prev -> next = temp -> next;
                temp -> next = NULL;
                temp =  NULL;
                // printf("Hii");
            }
        }
        else {
            
            prev = temp;
            temp = temp -> next;
        }
    }
}

//Search function
void search() {
    int value;
    struct node *temp;
    printf("Enter the value you want to search: ");
    scanf("%d",&value);
    temp = head;
    while(temp -> next != NULL && temp -> data != value) {
        temp = temp -> next;
    }
    if(temp -> data == value) {
        printf("Value found");
    }
    else {
        printf("Value not found");
    }
}
 
void main() {
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
        case 4: insertafter();
        break;
        case 5: delete();
        break;
        case 6: display();
        break;
        case 7: search();
        break;
        default: printf("Invalid case!");
        break;
    }
        printf("\nEnter 9 to continue: ");
        scanf("%d",&ans);
    }
}

