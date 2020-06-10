#include<stdio.h>
#include<conio.h>
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void bubblesort(int A[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j< n-i-1;j++)
        {
           if(A[j] > A[j+1])
           {
               swap(&A[j],&A[j+1]);
           }
        }
    }
}
void selectionSort(int Arr[],int n)
{
  int i,j,min;
  for(i=0;i<n;i++)
  {
      min = i;
      for(j=i+1;j<n;j++)
      {
          if(Arr[j] < Arr[min])
            min = j;
      }
      swap(&Arr[min],&Arr[i]);
  }
}
void insertionsort(int Ar[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = Ar[i];
        j = i - 1;
        while(j>=0 && Ar[j]>key)
        {
            Ar[j+1] = Ar[j];
            j = j-1;
        }
        Ar[j+1]=key;
    }
}
void main()
{
int A[7]={34,2,56,1,8,99,3},n=7,i;
int Arr[7] = {45,34,12,76,2,6,1};
int Ar[7] = {45,134,1113,76,2,100,1};
bubblesort(A,n);
selectionSort(Arr,n);
insertionsort(Ar,n);
for(i=0;i<n;i++)
 printf("%d -- ",A[i]);
printf("\n\n");
for(i=0;i<n;i++)
 printf("%d -- ",Arr[i]);
printf("\n\n");
for(i=0;i<n;i++)
 printf("%d -- ",Ar[i]);
}
