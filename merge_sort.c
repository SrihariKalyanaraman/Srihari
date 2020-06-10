#include<stdio.h>
merge(int A[],int l,int m,int h)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  h - m;

    int B[n1], C[n2];

    for (i = 0; i < n1; i++)
        B[i] = A[l + i];
    for (j = 0; j < n2; j++)
        C[j] = A[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = B[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = C[j];
        j++;
        k++;
    }
}
merge_sort(int A[],int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        merge_sort(A,l,mid);
        merge_sort(A,mid+1,h);
        merge(A,l,mid,h);
    }

}
void main()
{
    int A[8] = {23,4,67,698,11,33,2,56},c;
    merge_sort(A,0,7);
    for(c = 0;c<8;c++)
        printf("%d \t",A[c]);

}
