#include<stdio.h>
#include<stdlib.h>
struct Node  {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    int front,rear;
    int capacity;
    struct Node **array;
};
struct Node* createNod() {
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->left=NULL;
    n->right=NULL;
    return(n);
}

struct Queue* createQueue() {
    struct Queue *Q;
    Q=(struct Queue *) malloc(sizeof(struct Queue));
    if(!Q)
        return(NULL);
    Q->capacity=10;
    Q->front=-1;
    Q->rear=-1;
    Q->array= (struct Node **) malloc(Q->capacity*sizeof(struct Node*));
    if(!Q->array)
        return(NULL);
    return(Q);
}
int isEmpty(struct Queue *Q) {
    return(Q->front==-1);
}
void enQueue(struct Queue *Q,struct Node *item) {

    Q->rear=(Q->rear+1)%Q->capacity;
    Q->array[Q->rear]=item;
    if(Q->front==-1)
        Q->front=Q->rear;

}
struct Node* deQueue(struct Queue *Q) {
    struct Node *d;
    if(isEmpty(Q)) {
        printf("\nQueu is empty");
        return(NULL);
    }
    else
    {
        d = Q->array[Q->front];
        if (Q->front==Q->rear) {
            Q->front =-1;
            Q->rear=-1;
        }
        else
            Q->front= (Q->front+1) % Q->capacity;
    }
    return(d);
}
void deleteQueue(struct Queue *Q)
{
    free(Q->array);
    free(Q);
}

void levelOrder(struct Node *root)
{
    struct Queue *Q;
    Q=createQueue();
    //printf("jfdhgsgd");
    struct Node *temp;

    if(!root)
        return;
    enQueue(Q,root);
    while(!isEmpty(Q))
    {
        temp=deQueue(Q);
        printf("%d ",temp->data);
        if(temp->left)
            enQueue(Q,temp->left);
        if(temp->right)
            enQueue(Q,temp->right);
    }
    deleteQueue(Q);
}
int main()
{
//  printf("jfdhgsgd");
    struct Node *root=NULL,*t;
  //  printf("jfdhgsgd");
    root=createNod();
    root->data=1;
    root->left=createNod();
    root->left->data=2;
    root->right=createNod();
    root->right->data=3;
//printf("jfdhgsgd");
    t=root->left;
    t->left=createNod();
    t->left->data=4;
    t->right=createNod();
    t->right->data=5;
   // printf("jfdhgsgd");
  //  printf("\n root = %u",root);
   levelOrder(root);
    return 0;
}