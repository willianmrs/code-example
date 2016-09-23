#include<stdlib.h>
#define ItemType int
#define TAM 10
typedef struct{
    ItemType data;
    struct Node* next;
}Node;

typedef struct{
    Node* first;
    Node* last;
    int qtd;
}Queue;

Queue *createQueue(){
    Queue* q=(Queue*)calloc(1,sizeof(Queue)); // Aloca a fila dinamicamente
    return q;
}

int enqueue(Queue * q, ItemType* e){
   Node* no = (Node*)calloc(1,sizeof(Node));
   Node* aux;
   no->data=*e;
   if(isEmptyQueue(q)){ //Insere o primeiro elemento da fila
        q->first=no;
        q->last=no;
        q->qtd++;
        return 1;
    }
    q->last->next=no;  //Insere o elemento no final da fila
    q->last=no;
    q->qtd++;
    return 1;
}
int dequeue(Queue* q, ItemType* e){
     if(isEmptyQueue(q)){  // Verifica se a pilha esta vazia
        return 0;
    }
    Node* aux;
    aux=q->first;
    *e=aux->data;
    q->first=aux->next;
    free(aux);
    q->qtd--;
    if(isEmptyQueue(q)){ // Caso apos a remoção a fila estiver vazia o ponteiro Last aponta pra NULL.
        q->last=NULL;
    }
    return 1;
}

int peek(Queue* q, ItemType* e){
    if(isEmptyQueue(q)) return 0;
    Node* aux;
    aux=q->first;
    *e=aux->data;
    return 1;
}
int contains(Queue* q, ItemType *e){
    if(isEmptyQueue(q)) return -1; //Pilha Vazia
    Node*aux = q->first;
    while(aux!=NULL){
        if(*e==aux->data) return 1; // Acho o Elemento
        aux=aux->next;
    }
    return 0; // Não Encontrou o elemento
}
int sizeQueue(Queue* q){
    return q->qtd;
}

int isEmptyQueue(Queue* q){
    return(q->first==NULL); // Verifica se a fila esta vazia
}

void printQueue(Queue* q){
    Node* aux=q->first;
        while(aux!=NULL){ // Imprime os elementos enquanto o aux for diferente de NULL
        printf("\nprintElement:%d",aux->data);
        aux=aux->next;
    }
}
/*
Queue *createQueue ();                                           // Criar a fila
void initializeQueue(Queue *q);                                  // Inicializa a fila
int enqueue(Queue * q, ItemType e);                              // Insere um elemento na fila
int dequeue(Queue* q, ItemType* e);                              // Remover um elemento da fila
int peek(Queue* q, ItemType* e);                                 // Recuperar informações do primeiro da fila
int contains(Queue* q, ItemType *e);                             // Verificar se um elemento está na fila
int sizeQueue(Queue* q);                                         // Verificar quantos elementos existem na fila
int isEmptyQueue(Queue* q);                                      // Verificar se a fila está vazia
int isFullQueue(Queue* q);                                       // Verificar se a fila está cheia
void printQueue(Queue* q);                                       // Ver todo o conteúdo da fila.
*/
