#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

struct Queue {
    int size;
    int front;
    int rear;
    Node** Q;
};

void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node**)malloc(q->size * sizeof(Node*));
}

void enqueue(struct Queue* q, Node* x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue* q)
{
    Node* x = NULL;

    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q) { return q.front == q.rear; }

struct Node* root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("enter root value");
    scanf("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q, root);
    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node* p)
{
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void ineorder(struct Node* p)
{
    if (p) {
        ineorder(p->lchild);
        printf("%d ", p->data);
        ineorder(p->rchild);
    }
}

int main(int argc, char* argv[])
{

    Treecreate();
    preorder(root);
    printf("\n");
    return 0;
}
