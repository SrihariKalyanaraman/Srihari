#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
int *first;
struct Node* newNode(int x){

   struct Node* node = malloc(sizeof(struct Node));
   node->data = x;
   node->next = NULL;
   return node;
};
void insertfirst(struct Node* p,int x1){
  struct Node* temp = newNode(x1);
  temp->next = p;
  first = temp;
}

void printlist(struct Node* p){
for(p=first;p != NULL;p=p->next){
    printf("%d--",p->data);
}
}
void main()
{
    struct Node* p = newNode(5);
    first = p;
    p->next = newNode(10);
    p->next->next = newNode(15);
    printlist(p);
    printf("\n");
    insertfirst(p,50);
    printlist(p);
}
