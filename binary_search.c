#include<stdio.h>
int binary_search(int A[],int l,int h,int x)
{
    int flag =0;
    if(h >= l)
    {
    int mid = (l+(h))/2;
    if(A[mid] == x)
        return 1;
    if(x < A[mid])
       return binary_search(A,l,mid-1,x);
    if(x > A[mid])
       return binary_search(A,mid+1,h,x);
    }
    return 0;
}
void main()
{
    int x,A[8] = {4,5,6,7,23,76,121,333};
    printf("Enter the element to be searched\n");
    scanf("%d",&x);
    if(binary_search(A,0,7,x) == 1)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present");
    }
}
