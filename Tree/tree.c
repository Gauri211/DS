#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root, *temp;
    
struct node *createnode() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d",&x);
    if(x == -1) {
        return 0;
    }
        newnode -> data = x;
        printf("Enter left child of %d: \n",x);
        newnode -> left = createnode();
        printf("Enter right child of %d: \n",x);
        newnode -> right = createnode();
        return newnode;
    
}

void Preorder(struct node *root) {
    if(root == NULL){
        return ;
    }
    printf("%d",root -> data);
    Preorder(root -> left);
    Preorder(root -> right);
}

void Inorder(struct node *root) {
    if(root == NULL) {
        return ;
    }
    Inorder(root -> left);
    printf("%d",root -> data);
    Inorder(root -> right);
}

void Postorder(struct node *root) {
    if(root == NULL) {
        return ;
    }
    Postorder(root -> left);
    Postorder(root -> right);
    printf("%d",root -> data);
}

void delete(struct node *temp) {
    struct node *temp, *ptr;
    int value;
    int x;
    if(x == -1) {
        return 0;
    }
    // printf("Enter data of left node which is to be deleted: ");
    // scanf("%d",&value);
    if(root == NULL) {
        return ;
    }
    else {
        temp = root;
        ptr = root;
        if(temp -> data == value){
            // temp = temp -> left;
            free(temp);
        }
        else if(ptr -> data == value) {
            free(ptr);
        }
        else {
            temp = temp -> left;
        }
        delete(temp -> left);
        delete(temp -> right);
    }
}
void main() {
    root = NULL;
    root = createnode();
    temp -> data = 5;
    int n,num = 0;
    
    while(num == 0) {
        printf("Enter case: ");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("Preorder is: ");
                    Preorder(root);
                    printf("\nInorder is: ");
                    Inorder(root);
                    printf("\nPostorder is: ");
                    Postorder(root);
                break;
            case 2: delete(temp);
                break;
            default: printf("Invalid case!");
                break;
        }
        printf("Enter: ");
        scanf("%d",&num);
    }

    
    // printf("\n%d,%d",root -> left -> data , root -> right -> data);
}