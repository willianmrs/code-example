typedef struct{
int d;
int m;
int y;
}Date;

Date* createDate(int d, int m, int y){
    Date* data=(Date*) calloc(1,sizeof(Date));
    data->d=d;
    data->m=m;
    data->y=y;
    return data;
}

int getDate(Date *date, char* str){
    str = sprintf(str,"%d/%d/%d\n", date->d,date->m,date->y);
    return 1;
}

int getAmericanDate(Date *date, char* str){
    str = sprintf(str,"%d/%d/%d\n", date->m,date->d,date->y);
    return 1;
}

int setDate(Date *date, int d, int m, int y){
    date->d=d;
    date->m=m;
    date->y=y;
    return 1;
}

int getDay(Date *date){
    return date->d;
}

int getMonth(Date *date){
    return date->m;
}

int getYear(Date *date){
    return date->y;
}

int getWritingMonth(Date *date){
    switch(date->m){
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Março");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
        default: printf("Erro: Formato Incorreto");
    }
}

int checkDate(Date *date){
    if(date->d<31 && date->m<12)
        return 1;

    return 0;
}


/*
Date* createDate(int d, int m, int y);          //Criar uma data
int getDate(Date *date, char* str);             //Recuperar a data no formato brasileiro
int getAmericanDate(Date *date, char* str);     //Recuperar a data no formato americano
int setDate(Date *date, int d, int m, int y);   //Alterar a data
int getDay(Date *date);                         //Recuperar somente o dia da data
int getMonth(Date *date);                       //Recuperar somente o mês da data
int getWritingMonth(Date *date);                //Recuperar o mês da data por extenso
int getYear(Date *date);                        //Recuperar somente o ano da data
int checkDate(Date *date);                      //Validar uma data
*/
