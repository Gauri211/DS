#include<stdio.h>
int min(int x,int y)
{
    int m=x<y?x:y;
    return m;
}
int fibosearch(int s,int n,int a[])
{
    int offset=-1,fibm1=1,fibm2=0,fibm=fibm1+fibm2,i;
    while(fibm<n)
    {
        fibm2=fibm1;
        fibm1=fibm;
        fibm=fibm1+fibm2;
    }
    while(fibm>1)
    {
        i=min(offset+fibm2,n-1);
        if(s>a[i])
        {
            fibm=fibm1;
            fibm1=fibm2;
            fibm2=fibm-fibm1;
            offset=i;
        }
        else if(s<a[i])
        {
            fibm=fibm2;
            fibm1=fibm1-fibm2;
            fibm2=fibm-fibm1;
        }
        else
        return i;
    }
    return -1;
}
void main()
{
    int n,a[20],i,search,flag=-1;
    printf("enter number of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     printf("enter number ");
     scanf("%d",&a[i]);
    }
    printf("enter search ");
    scanf("%d",&search);
    flag=fibosearch(search,n,a);
    if(flag!=-1)
    printf("element found at %d",flag);
    else
    printf("element not found");
}