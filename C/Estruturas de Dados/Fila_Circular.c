#define ItemType int
#define TAM 10
typedef struct{
    int first;
    int last;
    int length;
    ItemType *itens;
}Queue;

/*Queue *createQueue ();                  // Criar a fila
void initializeQueue(Queue *q);         // Inicializa a fila
int enqueue(Queue * q, ItemType e);     // Inserir um elemento na fila;
int dequeue(Queue* q, ItemType* e);     // Remover um elemento da fila
int peek(Queue* q, ItemType* e);        // Recuperar informações do primeiro da fila
int contains(Queue* q, ItemType *e);    // Verificar se um elemento está na fila
int sizeQueue(Queue* q);                // Verificar quantos elementos existem na fila
int isEmptyQueue(Queue* q);             // Verificar se a fila está vazia
int isFullQueue(Queue* q);              // Verificar se a fila está cheia
void printQueue(Queue* q);              // Ver todo o conteúdo da fila.
*/
Queue *createQueue (){
    Queue* q=(Queue*) calloc(1,sizeof(Queue));
    q->length=TAM;
    q->itens=(ItemType*) calloc(q->length,sizeof(ItemType));
    return q;
}

void initializeQueue(Queue *q){
    q->first=0;
    q->last=0;
}

int enqueue(Queue *q, ItemType e){
    if(isFullQueue(q))
        return 0;
    q->itens[q->last]=e;
    q->last=(q->last+1)%q->length;
    return 1;
}

int dequeue(Queue* q, ItemType* e){
    if(isEmptyQueue(q))
        return 0;
    *e=q->itens[q->first];
    q->first=(q->first+1)%q->length;
    return 1;
}

int peek(Queue* q, ItemType* e){
    if(isEmptyQueue(q))
        return 0;

    *e=q->itens[q->first];
    return 1;
}

int contains(Queue* q, ItemType *e){
    if(isEmptyQueue(q))
        return -1;
    int i=q->first;
    while(i!=q->last){
        if(q->itens[i]==*e)
            return i;
        i=(i+1)%q->length;
    }
    return -1;
}

int sizeQueue(Queue* q){
    return(q->first < q->last ? q->last - q->first : q->length-(q->first-q->last));
}

int isEmptyQueue(Queue* q){
    return(q->last == q->first);
}

int isFullQueue(Queue* q){
    return ((q->last+1)%q->length == q->first);
}

void printQueue(Queue* q){
    int i=q->first;
    while(i!=q->last){
        printf("%d\n",q->itens[i]);
        i=(i+1)%q->length;
    }
}
