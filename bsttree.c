#include<stdio.h>
#include<stdlib.h>
int c = 0;
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node* newNode(int x)
{
  struct Node* node = malloc(sizeof(struct Node));
  node->data = x;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void printdescorder(struct Node *p)
{
    if(p)
    {
    printdescorder(p->right);
    printf("%d",p->data);
    printdescorder(p->left);
    }
}
void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d --" , p->data);
        inorder(p->right);
    }
}
int searchandprint(struct Node *p,int x)
{
    if(p)
    {
        if(p->data == x)
        {
        c++;
        return c;
        }
        if(x < p->data)
        {
         c++;
         searchandprint(p->left,x);
        }
        if(x > p->data)
        {
        c++;
        searchandprint(p->right,x);
        }
    }
}
void inorderpredsucc(struct Node *p,int val)
{
    int predecessor,successor;
    if (p) {
			if (p->data == val) {
				if (p->left) {
					struct Node *t = p->left;
					while (t->right) {
						t = t->right;
					}
					predecessor = t->data;
				}
				if (p->right) {
					struct Node *t = p->right;
					while (t->left) {
						t = t->left;
					}
					successor = t->data;
				}
			} else if (p->data > val) {
				successor = p->data;
				inorderpredsucc(p->left, val);
			} else if (p->data < val) {
				predecessor = p->data;
				inorderpredsucc(p->right, val);
			}
		}
	printf("\n The predecessor is %d and the successor is %d\n",predecessor,successor);
}
struct Node* insertBST(struct Node *p,int x)
{
    if (!p)
    return newNode(x);
    if(x < p->data)
    p->left  = insertBST(p->left, x);
    if(x > p->data)
    p->right = insertBST(p->right,x);

    return p;
}
struct Node* findMinimum(struct Node* cur)
{
    while(cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}
void search(struct Node* curr, int key, struct Node* parent)
{
	while (curr != NULL && curr->data != key)
	{
		parent = curr;
		if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
}

void deleteBST(struct Node* root, int item)
{
    struct Node* parent = NULL;
    struct Node* cur = root;

    search(cur, item, parent);
    if (cur == NULL)
        return;

    if (cur->left == NULL && cur->right == NULL)
    {
        if (cur != root)
        {
            if (parent->left == cur)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;

        free(cur);
    }
    else if (cur->left && cur->right)
    {
        struct Node* succ  = findMinimum(cur->right);

        int val = succ->data;

        deleteBST(root, succ->data);

        cur->data = val;
    }

    else
    {
        struct Node* child = (cur->left)? cur->left: cur->right;

        if (cur != root)
        {
            if (cur == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }

        else
            root = child;
        free(cur);
    }
}
int main()
{
    int n,n1,x2,x3;
  struct Node *root = newNode(55);
    root->left = newNode(33);
    root->right = newNode(77);
    root->left->left = newNode(22);
    root->left->right = newNode(44);
    root->right->left = newNode(66);
    root->right->right = newNode(88);

    printdescorder(root);
    printf("\nEnter the number");
    scanf("%d",&n);
    printf("%d",searchandprint(root,n));
    printf("\n Enter the number to be inserted ");
    scanf("%d",&x2);
    insertBST(root,x2);
    inorder(root);
    printf("Enter the node number to which inorder predecessor and successor needs to be find : ");
    scanf("%d",&n1);
    inorderpredsucc(root,n1);
    printf("Enter the number to be deleted\n");
    scanf("%d",&x3);
    deleteBST(root,x3);
    inorder(root);
  return 0;
}

