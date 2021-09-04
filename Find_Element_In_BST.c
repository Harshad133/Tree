#include<stdio.h>

struct BSTNode  {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};


struct BSTNode* createNod() {
    struct BSTNode *n;
    n=(struct BSTNode *)malloc(sizeof(struct BSTNode));
    n->left=NULL;
    n->right=NULL;
    return(n);
}

struct BSTNode * Find(struct BSTNode *root, int d)
{
    if(root==NULL)
        return(NULL);
    if(d<root->data)
        return(Find(root->left,d));
    else if(d>root->data)
        return(Find(root->right,d));
    return(root);
}

int main()
{
    struct BSTNode *root=NULL,*t;
    root=createNod();
    root->data=5;
    root->left=createNod();
    root->left->data=2;
    root->right=createNod();
    root->right->data=6;

    t=root->left;
    t->left=createNod();
    t->left->data=1;
    t->right=createNod();
    t->right->data=3;

    struct BSTNode *f;
    f=Find(root,0);
    printf("%u",f);
    return 0;
}