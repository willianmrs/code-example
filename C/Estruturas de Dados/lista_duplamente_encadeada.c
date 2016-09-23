#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ItemType int

typedef struct node{
	ItemType data;
	struct node *prev;
	struct node *next;
}Node;

typedef struct{
	Node *first;
	Node *last;
	int tam;
}List;

List *createList(){
List *l = (List*) calloc(1,sizeof(List));
	l->first = NULL;
	l->last = NULL;
	l->tam = 0;
return l;
}

int isEmptyList(List* l){
	return (l->tam == 0);
}

int removeList(List* l, int index, ItemType *e){
	if(isEmptyList(l)){
		return 0;
	}
	if(index == 0){
		*e = l->first->data;
		Node* aux = l->first;
		l->first = aux->next;
		l->first->prev = NULL;
		free(aux);
		return 1;
	}
	if(index == l->tam){
		*e = l->last->data;
		Node* aux = l->last;
		l->last = aux->prev;
		l->last->next = NULL;
		free(aux);
		return 1;
	}
	int i = 1;
	Node *ant = l->first;
	Node *aux = l->first->next;
	while(i != index-1){
		ant = aux;
		aux = aux->next;
		i++;
	}
	*e = aux->data;
	aux = aux->next;
	ant->next = aux;
	aux->prev = ant;
	free(ant->next);
	l->tam--;
	return 1;
}


int addLastList(List *l, ItemType e){
Node* new = (Node*) calloc(1,sizeof(Node));
new->data = e;
new->next = NULL;
	if(l->tam == 0){
			new->prev = NULL;
			l->first = new;
			l->last = new;
			l->tam++;
			return 1;
	}
	new->prev = l->last;
	l->last->next = new;
	l->last = new;
	l->tam++;
	return 1;
}

int addList(List* l, ItemType e, int index){
Node *new = (Node*) calloc(1,sizeof(Node));
new->data = e;
	if(index == 0){
			new->prev = NULL;
			new->next = l->first;
			l->first->prev = new;
			l->first = new;
			l->tam++;
			return 1;
	}
	if(index == l->tam){
			new->next = NULL;
			new->prev = l->last;
			l->last->next = new;
			l->last = new;
			l->tam++;
			return 1;
	}
	int i = 1;
	Node *ant = l->first;
	Node *aux = l->first->next;
	while(i != index){
		ant = aux;
		aux = aux->next;
		i++;
	}
	ant->next = new;
	aux->prev = new;
	new->prev = ant;
	new->next = aux;
	l->tam++;
	return 1;
}

printfList(List* l){
	if(isEmptyList(l)){
		printf("Lista Vazia");
	}
	Node* aux = l->first;
	while(aux->next != NULL){
		printf("%d , ", aux->data);
		aux = aux->next;
	}
	printf("%d . ", aux->data);
}
