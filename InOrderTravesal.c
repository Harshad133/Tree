#include<stdio.h>

struct Node  {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNod() {
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->left=NULL;
    n->right=NULL;
    return(n);
}

void inOrder(struct Node *root)
{
    if(root)
    {
        inOrder(root->left);
        printf(" %d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root)
{
    if(root)
    {
        printf(" %d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root=NULL,*t;
    root=createNod();
    root->data=1;
    root->left=createNod();
    root->left->data=2;
    root->right=createNod();
    root->right->data=3;

    t=root->left;
    t->left=createNod();
    t->left->data=4;
    t->right=createNod();
    t->right->data=5;

    printf("preodrerd ==   \n");
    preOrder(root);
    printf("\n");
    printf("inodrerd ==   \n");
    inOrder(root);

    return 0;
}