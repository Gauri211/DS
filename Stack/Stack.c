#include<stdio.h>

#define MAX 10      
int stack[MAX];     
int top = -1;            

void push() {
   int num;
   printf("Enter the number to be inserted: ");
   scanf("%d",&num);
   if(top == MAX-1) {
      printf("Overflow");
   }
   else if(top == -1) {
      top = 0;
   }
   else {
      top++;
   }
   stack[top] = num;
}

void pop() {
   if(top == -1) {
      printf("Underflow");
   }
   else {
      printf("The deleted number is %d", stack[top]);
      top--;
   }
}

void peek() {
   if(top == -1) {
      printf("Underflow");
   }
   else {
      printf("The peek number is %d", stack[top]);
   }
}

void display() {
   int i;
   if(top == -1) {
      printf("Underflow");
   }
   else {
      for(i=0; i<=top; i++) {
         printf("%d\t", stack[i]);
      }
   }
}

void main() {
   int n = 1;
    while(n != 0) {
        printf("Enter operation: ");
        scanf("%d",&n);
        switch(n) {
            case 1: push();
                break;
            case 2: pop();
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
