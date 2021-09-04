#include<stdio.h>

struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

void trave(struct BSTNode *root)
{
    if(root)
    {
        printf("%d ",root->data);
        trave(root->left);
        trave(root->right);
    }
}
struct BSTNode* insert(struct BSTNode *root, int v)
{
    struct BSTNode *p;
    struct BSTNode *n=(struct BSTNode *)malloc(sizeof(struct BSTNode));
    n->left=NULL;
    n->right=NULL;
    n->data=v;

    if(root==NULL)
    {
        root=n;
        return(root);
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            if(p->data>v)
            {
                if(p->left==NULL) {
                    p->left=n;
                    return(root);
                }
                p=p->left;
            }
            else if(p->data<v)
            {
                if(p->right==NULL) {
                    p->right=n;
                    return(root);
                }
                p=p->right;
            }
        }
    }

}
int main()
{
    struct BSTNode *root=NULL;
    int i=1,v;
    while(i)
    {
        printf("entr node value = ");
        scanf("%d",&v);
        root=insert(root,v);

        printf("do you enter new value in tree  =");
        scanf("%d",&i);
    }
    trave(root);
    return 0;
}