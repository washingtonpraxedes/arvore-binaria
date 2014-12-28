#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int telefone,rg;
    char nome[20] ;
    char email[20] ;
    struct No *esquerda;
    struct No *direita;
}No;


int main()
{
    printf("Hello world!\n");
    return 0;
}




void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

