#include<stdio.h>
#include<ctype.h>

#define MAX 100
int top = -1;
float st[MAX];

void push(float st[], float val) {
    if(top == MAX-1) {
        printf("Stack overflow");
    }
    else {
        top++;
        st[top] = val;
    }
}

float pop(float st[]) {
    int val;
    if(top == -1) {
        printf("Stack Underflow");
    }
    else {
        val = st[top];
        top--;
    }
    return val;
}

float evaluatePostfix(char exp[]) {
    
}