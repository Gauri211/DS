#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int left = -1, right = -1;


void insertRight() {
    if(left == -1) {
        left = 0;
        right = 0;
    }

}
void insertLeft() {
    int data;
    scanf("%d", &data);
    if(left == -1) {
        left = 0;
        right = 0;
    }
    else {
    }
}



void main(){
    int s, flag =1;
    while(flag){
        printf("\nEnter\n1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.Display\n6.Exit\n : ");
        scanf("%d", &s);
        switch(s){
            case 1:insertFront();break;
            case 2:insertRear();break;
            case 3:deleteFront();break;
            case 4:deleteRear();break;
            case 5:display();break;
            case 6:flag=0;break;
            default : printf("Wrong Input");
        }
    }
}