#include <stdio.h>
#include "tira_espaco.c"

typedef struct {
char* str;
int tam;
int pos;
}TokenReader;

int verifica(char*c){
    char delimitadores[100];
    int i;
    if((fp = fopen("Delim.txt","r")) == NULL){
        printf("Erro ao abrir arquivo!!!\n");
        exit(1);
    }
    fgets(delimitadores,100,fp);
    tira_espaco(delimitadores);
    for(i=0;delimitadores[i];i++){
        if(c==delimitadores[i]){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

char* subString(char* s, int beginIndex, int endIndex){
    int strsize,i;
    strsize = endIndex - beginIndex;
    char* str = (char*)calloc(strsize+1,sizeof(char));
    strncpy(str, (s+beginIndex), strsize);
    str[strsize+1]='\0';
    return str;
}

TokenReader *newTokenReader(char *str){
    TokenReader* reader=(TokenReader*) calloc(1,sizeof(TokenReader));
    reader->tam=strlen(str)+1;
    reader->str=(char*) calloc(reader->tam,sizeof(char));
    strcpy(reader->str,str);
    return reader;
}

void freeTokenReader(TokenReader *reader){
    free(reader->str);
    free(reader);
}

char* nextToken(TokenReader *reader){
    int inicio,fim;
    while(reader->str[reader->pos]==' '){
        reader->pos++;
    }
    inicio = reader->pos;
    while(verifica(reader->str[reader->pos])){
        reader->pos++;
    }
    fim = reader->pos;
    if(inicio==fim){
        fim++;
        reader->pos++;
    }
    return subString(reader->str,inicio,fim);
}

void setTokenString(TokenReader *reader, char* str){
    free(reader->str);
    reader->tam=strlen(str);
    reader->str=(char*) calloc(reader->tam,sizeof(char));
    strcpy(reader->str,str);
    reader->pos=0;
    return reader;
}

int hasMoreTokens(TokenReader *reader){
    while(reader->str[reader->pos]==' '){
        reader->pos++;
    }
    return (reader->str[reader->pos]=='\0' ? 0 : 1  );
}


/*
TokenReader *newTokenReader(char *str);
void freeTokenReader(TokenReader *reader);
char* nextToken(TokenReader *reader);
void setTokenString(TokenReader *reader, char* str);
int hasMoreTokens(TokenReader *reader);
char* subString(char* s, int beginIndex, int endIndex);
*/
