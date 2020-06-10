#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void quick_sort(int A[],int l,int h)
{
    if(l<h)
    {
        int i = l,j=h,pivot = A[l];
        while(i<j)
        {
            while(A[i] <= pivot)
            i++;
            while(A[j]>pivot)
            j--;
            if(i<j)
            swap(&A[i],&A[j]);
        }
        swap(&A[l],&A[j]);
        quick_sort(A,l,j);
        quick_sort(A,j+1,h);
    }
}
void main()
{
    int A[8] = {21,43,2,55,13,5,76,8},r;
    quick_sort(A,0,7);
    for(r = 0;r<8;r++)
        printf("%d\t",A[r]);

}
