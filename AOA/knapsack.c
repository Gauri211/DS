#include<stdio.h>

struct node {
    int id;
    float p, w, ratio;
}knapsack[10];

void main() {
    int n, min;
    float sp, m;
    struct node temp;
    printf("Enter the no of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%f", &m);
    for(int i=0; i<n; i++) {
        printf("Enter profit and weight of I%d: ", i+1);
        scanf("%f%f", &knapsack[i].p, &knapsack[i].w);
        knapsack[i].ratio = knapsack[i].p/knapsack[i].w;
        knapsack[i].id = i+1;
    }

    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (knapsack[j].ratio> knapsack[min].ratio)
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = knapsack[min];
            knapsack[min] = knapsack[i];
            knapsack[i] = temp;
        }
    }

    int k=0;
    while(m > 0) {
        if(m >= knapsack[k].w) {
            sp += knapsack[k].p;
            m -= knapsack[k].w;
            printf("Select Item I%d\n", knapsack[k].id);
            k++;
        }
        else {
            sp += knapsack[k].ratio * m;
            printf("Select %.2f part of Item I%d\n", knapsack[k].ratio*m, knapsack[k].id);
            m = 0;
        }
    }

    printf("The total profit is %.2f", sp);
}