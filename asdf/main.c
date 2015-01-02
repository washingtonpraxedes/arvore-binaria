
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no *esq;
	struct no *dir;
	int telefone,rg;
    char nome[20];
    char email[20];
    int index;
}no;

int index=0;


void inserirNo(no **raiz,int telefone, int rg, char nome[20], char email[20])
{
	if(*raiz == NULL) {
    	no *aux = (no *)malloc(sizeof(no));
    	aux->telefone = telefone;
    	aux->rg = rg;
    	aux->dir = aux->esq = NULL;
    	*raiz = aux;
    	printf("Elemento foi inserido com sucesso.\n");
    	index++;
    	return;
	}
	if(index < (*raiz)->index) {
    	inserirNo(&(*raiz)->esq,telefone, rg,  nome,  email);
    	return;
	}
	if(index > (*raiz)->index) {
    	inserirNo(&(*raiz)->dir,telefone, rg,  nome,  email);
    	return;
	}
	printf("Elemento ja existe na arvore.\n");

	}





int main()
{
while(1){
    int opt;
    printf("Escolha Opcao:");
    printf("\n");
    printf("[1]- Cadastrar Numero");
    printf("\n");
    printf("[2]- Pesquisar Numero");
    printf("\n");
    printf("[3]- Remover Numero");
    printf("\n");
    printf("[4]- Listar Cadastros");
    printf("\n");
    scanf("%d",&opt);

    switch(opt){
    case 1:
        printf("Novo numero: ");
        int telefone;
        scanf("%d",&telefone);
        printf("Nome: ");
        char nome[20];
        scanf("%s",nome);
        printf("RG: ");
        int rg;
        scanf("%d",&rg);
        printf("Email: ");
        char email[20];
        scanf("%s",email);
        no *raiz = NULL;
        inserirNo(&raiz,  telefone, rg,  nome,  email);
    }

}


	return 0;

}

