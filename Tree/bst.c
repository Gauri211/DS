#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root;

struct node *createnode(int val) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node *insert(struct node *new, int data) {
    if(new == NULL) {
        return createnode(data);
    }
    if(data < new -> data) {
        new -> left = insert(new -> left, data);
    }
    else {
        new -> right = insert(new -> right, data);
    }
    return new;
}

//to find the inorder successor
struct node *minValueNode(struct node *node) {
    struct node *current = node;
    //Find the leftmost leaf
    while(current && current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

//Deleting a node
struct node *delete(struct node *root, int data) {
    if(root == NULL) {
        return root;
    }
    
    if(data < root->data) {
        root -> left = delete(root -> left, data);
    }

    else if(data > root->data) {
        root -> right = delete(root->right, data);
    }

    else {
        //node with one or no child
        if(root -> left == NULL) {
            struct node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            struct node *temp = root -> left;
            free(root);
            return temp;
        }

        //node with two children
        struct node *temp = minValueNode(root -> right);
        root -> data = temp -> data;
        root -> right = delete(root -> right, temp -> data);
    }
    return root;
}

void Preorder(struct node *root) {
    if(root == NULL){
        return ;
    }
    printf("\t%d",root -> data);
    Preorder(root -> left);
    Preorder(root -> right);
}

void Inorder(struct node *root) {
    if(root == NULL) {
        return ;
    }
    Inorder(root -> left);
    printf("\t%d",root -> data);
    Inorder(root -> right);
}

void Postorder(struct node *root) {
    if(root == NULL) {
        return ;
    }
    Postorder(root -> left);
    Postorder(root -> right);
    printf("\t%d",root -> data);
}

void main() {
     struct node *root =    NULL;
     root = insert(root, 10);
     root = insert(root, 5);
     root = insert(root, 16);
     root = insert(root, 3);
     root = insert(root, 8);
     root = insert(root, 25);
     root = insert(root, 2);
     root = insert(root, 6);
     root = insert(root, 9);
     root = insert(root, 20);
     root = insert(root, 23);
     printf("\nInorder is: ");
     Inorder(root);
     printf("\nAfter deleting 5: \n");
     root = delete(root, 5);
     printf("Preorder is: ");
     Preorder(root);
     printf("\nInorder is: ");
     Inorder(root);
     printf("\nPostorder is: ");
     Postorder(root);

}

