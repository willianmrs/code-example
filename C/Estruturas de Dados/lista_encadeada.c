#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ItemType int

typedef struct node{
	ItemType data;
	struct node *next;
}Node;

typedef struct{
	Node *first;
	Node *last;
	int tam;
}List;

int sizeList(List* l){
	return l->tam;
}

int isEmptyList(List* l){
	return (l->tam==0) ;
}

int containsList(List* l, ItemType *e){
	if(isEmptyList(l)){
			return 0;
	}
	Node* aux = l->first;
	while(aux->data != *e){
		if(aux->next == NULL){
			return 0;
		}
		aux = aux->next;
	}
	return (*e == aux->data);
}

int indexOfList(List* l, ItemType* e){
ItemType el = *e;
	if(isEmptyList(l) || !containsList(l,&el)){
		return -1;
	}
	int i = 0;
	Node* aux = l->first;
	while(aux->data != *e){
		aux = aux->next;
		i++;
	}
return i;
}

int getList(List* l, int index, ItemType* e){
int i = 0;
	if(isEmptyList(l) || index > l->tam){
		return 0;
	}
	Node* aux = l->first;
	while(i != index){
			i++;
			aux = aux->next;
		}
	*e = aux->data;
return 1;
}

int setList(List* l, int index, ItemType* e){
int i = 0;
	if(isEmptyList(l) || index > l->tam){
		return 0;
	}
	Node* aux = l->first;
	while(i != index){
			i++;
			aux = aux->next;
		}
	aux->data = *e;
return 1;
}

printList(List* l){
	if(isEmptyList(l)){
		printf("Fila Vazia");
		return 0;
	}
	Node* aux = l->first;
	while(aux->next != NULL){
		printf("%d , ", aux->data);
		aux = aux->next;
	}
	printf("%d . ", aux->data);
}

int removeList(List* l, int index, ItemType *e){

	if(index > l->tam){
			return 0;
	}

	if(index == 0){
		Node* aux = l->first;
		l->first = aux->next;
		*e= l->first->data;
		free(aux);
		l->tam--;
		return 1;
	}
	if(index == l->tam){
		int i = 1;
		Node* ant = l->first;
		Node* aux = l->first->next;
		while(i != index){
			i++;
			ant = aux;
			aux = aux->next;
		}
		l->last = ant;
		ant->next = NULL;
		free(aux);
		l->tam--;
		return 1;
	}
	int i = 1;
		Node* ant = l->first;
		Node* aux = l->first->next;
		while(i != index){
			i++;
			ant = aux;
			aux = aux->next;
		}
		ant->next = aux->next;
		free(aux);
		l->tam--;
		return 1;
}

int removeElementList(List* l, ItemType* e){
ItemType aux = *e;
int pos = indexOfList(l,&aux);
	if(containsList(l,&aux) == 0){
		return 0;
	}
	removeList(l,pos,&aux);

	return pos;
}

int addList(List* l, ItemType e, int index){
Node *new = (Node*) calloc(1,sizeof(Node));
new->data = e;

	if(index > l->tam){
			return 0;
	}

	if(index == 0){
		Node* aux = l->first;
		l->first = new;
		l->first->next = aux;
		l->tam++;
		return 1;
	}
	if(index == l->tam){
		Node* aux = l->last;
		l->last = new;
		new->next = NULL;
		aux->next = l->last;
		l->tam++;
		return 1;
	}

	int i = 1;
	Node* ant = l->first;
	Node* aux = l->first->next;
	while(i != index){
		i++;
		ant = aux;
		aux = aux->next;
	}
		ant->next = new;
		new->next = aux;
		l->tam++;
		return 1;
}


int addLastList(List *l, ItemType e){
Node *new = (Node*) calloc(1,sizeof(Node));
new->data = e;
	if(l->tam == 0){
			new->next = NULL;
			l->first = new;
			l->last = new;
			l->tam++;
			return 1;
	}else{
		Node* aux = l->last;
		l->last = new;
		aux->next = new;
		l->last->next = NULL;
		l->tam++;
	}
return 1;
}

List *createList (){
	List *l = (List*) calloc(1,sizeof(List));
	l->tam = 0;
	l->first = NULL;
	l->last = NULL;
return l;
}
