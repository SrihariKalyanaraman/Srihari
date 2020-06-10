#include<stdio.h>
#define PRIME 7
int HT[10];
int h(int x)
{
    return x%10;
}
int f(int i)
{
    return i;
}
int h1(int x)
{
    return PRIME-(x%PRIME);
}
int isfilled(int HT[],int m)
{
    if(HT[m] == -1)
        return 0;
}
void insert_hash(int HT[],int r)
{
    int new_index,i=0,flag=0;
    while(flag == 0)
    {
    new_index = (h(r)+(f(i)*h1(r)))%10;
    if(!isfilled(HT,new_index))
       {
        HT[new_index]=r;
        flag = 1;
       }
    i++;
    }
    printf("The number of comparisons for %d is %d \n",r,i);
}
void print_ht(int HT[])
{
    int j;
    printf("THE HASH TABLE IS \n");
  for(j = 0;j<10;j++)
    printf("%d \n",HT[j]);
}
float load_factor(int HT[])
{
    float lf,count=0;
    int i;
    for(i=0;i<10;i++)
    if(isfilled(HT,i))
    count++;
    lf = count/10;
    return lf;
}
void main(){
    int i;
    for(i=0;i<10;i++)
        HT[i]=-1;
    insert_hash(HT,14);
    insert_hash(HT,32);
    insert_hash(HT,52);
    insert_hash(HT,39);
    print_ht(HT);
    printf("The Load Factor is %f " , load_factor(HT));
}
