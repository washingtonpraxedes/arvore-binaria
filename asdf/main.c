
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	struct no *esq;
	struct no *dir;
	int telefone,rg;
    char *nome;
    char *email;
}no;

no *raiz = NULL;


void inserirNo(no **raiz,int telefone, int rg, char *nome, char *email)
{
	if(*raiz == NULL) {
        printf("Entro no if 1 \n");
    	no *aux = (no *)malloc(sizeof(no));
    	aux->telefone = telefone;
    	aux->rg = rg;
    	aux-> nome=nome;
    	aux-> email= email;
    	aux->dir = aux->esq = NULL;
    	*raiz = aux;
    	printf("Elemento foi inserido com sucesso.\n");

    	printf("Raiz\n");
    	printf("%d\n",aux->telefone);
    	printf("%d\n",aux->rg);
    	printf("%s\n",aux->nome);
    	printf("%s\n",aux->email);
    	return;
	}
	if  (telefone<(*raiz)->telefone) {
        printf("Entrou no 2 if");
    	inserirNo(&(*raiz)->esq,telefone, rg,  nome,  email);
    	return;
	}


        if( telefone>(*raiz)->telefone) {
            printf("Entrou no 3 if");
            inserirNo(&(*raiz)->dir,telefone, rg,  nome,  email);
            return;
        }
        printf("Telefone %d ja existe na arvore.\n",telefone);

	}




	void listar(no *raiz)
{
	if(raiz == NULL){
    	return;
    }


        listar(raiz->esq);
        printf("Telefone :%d\n",raiz->telefone);
        printf("Nome: %s\n",raiz->nome);
        printf("RG: %d\n",raiz->rg);
        printf("Email: %s\n",raiz->email);


     if(raiz->dir!=NULL){
        listar(raiz->dir);
        }
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
        inserirNo(&raiz,  telefone, rg,  &nome,  &email);
        break;
    case 2:
        printf("Digite o numero de pesquisa: ");

        scanf("%d",&telefone);



    case 4:
        printf("Listando:\n");
        printf("Qual ordem vc deseja listar: \n");
        printf("[1]-Pre-ordem");
        printf("[2]-In-ordem");
        printf("[3]-Pos-ordem");
        int op;
        scanf("%d",&op);
        listar(&raiz);
        break;

    }


}


	return 0;

}

