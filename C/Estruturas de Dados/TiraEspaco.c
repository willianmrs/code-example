void tira_espaco(char* str){
    int tam = strlen(str)+1;
    char str2[tam];
    int contI=0,contF,i;
    contF=strlen(str);
    contF=contF-1;

    while( (str[contI] == ' ' ) || (str[contF]==' ' )){

        if(str[contI]== ' ')
            contI++;
        if(str[contF]==' ')
            contF--;
    }
    for(i=0;contI<=contF;contI++,i++){
        str2[i]=str[contI];
    }
    str2[i]= '\0';
    strcpy(str,str2);
}
