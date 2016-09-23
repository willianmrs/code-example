#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ItemType int
#define TAM 10
typedef struct{
    int tam;
    int length;
    ItemType *items;
}List;

List *createList (){
    List* lista=(List*)calloc(1,sizeof(List));
    lista->length=TAM;
    lista->items=(ItemType*)calloc(lista->length,sizeof(List));
    return lista;
}

int addLastList(List *l, ItemType e){
    if(isFullList(l)) return 0;
    l->items[l->tam]=e;
    l->tam++;
    return 1;
}

int addList(List* l, ItemType e, int index){
    if(isFullList(l) || index>l->tam ) return 0;
    if(index==(l->tam)) addLastList(l,e);
    memcpy(&l->items[index+1],&l->items[index],sizeof(ItemType)*(l->tam - index));
    l->items[index]=e;
    l->tam++;
    return 1;
}

int removeList(List* l, int index, ItemType *e){
    if(isEmptyList(l) || index>l->tam) return 0;
    memcpy(&l->items[index-1],&l->items[index],sizeof(ItemType)*(l->tam - index));
    l->tam--;
    return 1;
}

int removeElementList(List* l, ItemType* e){
    if(isEmptyList(l)) return -1;
    int i;
    for(i=0;i<l->length;i++){
        if(*e==l->items[i]){
            removeList(l,i,e);
            return 1;
        }
    }
    return -1;
}

int getList(List* l, int index, ItemType* e){
    if(index > l->tam) return 0;
    *e = l->items[index];
    return 1;
}

int setList(List* l, int index, ItemType* e){
    if(index > l->tam) return 0;
    l->items[index] = *e;
    return 1;
}

int indexOfList(List* l, ItemType* e){
    if(isEmptyList(l)) return -1;
    int i;
    for(i=0;i<l->length;i++){
        if(*e==l->items[i])return i;
    }
    return -1;
}

int containsList(List* l, ItemType *e){
    if(isEmptyList(l)) return 0;
    int i;
    for(i=0;i<l->length;i++){
        if(*e==l->items[i])return 1;
    }
    return 0;
}

int sizeList(List* l){
    return l->tam;
}


int isEmptyList(List* l){
    return (l->tam==0);
}

int isFullList(List* l){
    return  (l->length==l->tam);
}

void printList(List* l){
    int i;
    for(i=0;i<l->tam;i++){
        printf("\nPrint Element:%d",l->items[i]);
    }
}



/**memcpy(&Origem,&Destino,sizeof(Tipo)*(size-tam));*/
/*
List *createList ();
void initializeList(List *l);
int addLastList(List *l, ItemType e);
int addList(List* l, ItemType e, int index);
int removeList(List* l, int index, ItemType *e);
int removeElementList(List* l, ItemType* e);
int getList(List* l, int index, ItemType* e);
int setList(List* l, int index, ItemType* e);
int indexOfList(List* l, ItemType* e);
int containsList(List* l, ItemType *e);
int sizeList(List* l);
int isEmptyList(List* l);
void printList(List* l);
*/
