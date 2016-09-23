#define ItemType int
#define SIZE 1

typedef struct{

    ItemType* itens;
    int length;
    int top;

}Stack;

void dobraStack(Stack* p){
    int i;
    ItemType* s = calloc(p->length*2,sizeof(ItemType));
    for(i=0;i<(p->top);i++){
        s[i]=p->itens[i];
    }
    free(p->itens);
    p->length*=2;
    p->itens = s;
}


Stack* createStack(){
    Stack* p;
    p=(Stack*) calloc(1, sizeof(Stack));
    p->itens=(ItemType*) calloc(SIZE, sizeof(ItemType));
    p->length=SIZE;
    return p;
}


void initializeStack(Stack* p){
    p->top=0;
}


int push(Stack* p, ItemType e){
    if((p->length)==(p->top))
        dobraStack(p);

    p->itens[p->top]=e;
    p->top+=1;
    return 1;
}

int pop(Stack* p, ItemType* e){
    if((p->top)==0)
        return 0;

    p->top-=1;
    *e=p->itens[p->top];
    return 1;
}

int top(Stack* p, ItemType* e){
    *e=p->itens[p->top-1];
    return 1;
}

void printStack( Stack* p){
    int i;
    for(i=0;i<(p->top);i++)
    printf("%d\n",p->itens[i]);
}

int containsStack(Stack* p, ItemType *e){
    int i;
    for(i=0;i<p->top;i++){
        if(p->itens[i]==*e)
            return 1;
    }
    return 0;
}
int sizeStack(Stack* p){
    return p->top;
}

int isEmptyStack(Stack* p){
    if(p->top==0)
        return 1;
    else
        return 0;
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
