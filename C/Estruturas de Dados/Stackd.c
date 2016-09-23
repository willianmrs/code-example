#include<stdio.h>
#define ItemType int
typedef struct  {
    ItemType data;
    struct Node* next;
}Node;

typedef struct{
    int tam;
    Node* top;
}Stack;

Stack* createStack(){
    Stack* p=(Stack*) calloc (1,sizeof(Stack));
    p->top=NULL;
    return p;
}

int push(Stack* p, ItemType e){
    Node* node=(Node*) calloc(1, sizeof(Node));
    node->data=e;
    node->next=p->top;
    p->top=node;
    p->tam++;
    return 1;
}

int pop(Stack* p, ItemType* e){
    if(p->tam==0)return 0;
    Node* node;
    node = p->top;
    p->top=p->top->next;
    *e=node->data;
    free(node);
    p->tam--;
    return 1;
}

int top(Stack* p, ItemType* e){
    *e=p->top->data;
    return 1;
}

void printRec(Node* node){
    if(node->next!=NULL)
        printRec(node->next);

    printf("%d\n",node->data);
}

void printStack(Stack* p){
    if(p->tam==0){
        printf("\n Pilha Vazia");
    }
    else
    printRec(p->top);
}


int containsStack(Stack* p, ItemType *e){
    Node* node;
    node=p->top;
    while(node!=NULL){
        if(node->data==*e){
            return 1;
        }
        node=node->next;
    }
    return 0;
}

int sizeStack(Stack* p){
    return p->tam;
}

int isEmptyStack(Stack* p){
    return (p->tam==0 ? 1 : 0  );

}

/*
Stack* createStack();
void initializeStack(Stack* stack);
int push(Stack* stack, ItemType e);
int pop(Stack* stack, ItemType* e);
int top(Stack* stack, ItemType* e);
void printStack(Stack* stack);
int containsStack(Stack* stack, ItemType *e);
int sizeStack(Stack* stack);
int isEmptyStack(Stack* stack);
*/
