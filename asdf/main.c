
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
struct no *esq;
struct no *dir;
struct no *pai;
int telefone,rg;
char *nome;
char *email;
}no;

no *raiz; /*raiz da árvore*/

/*função que busca um nó em uma arvore de raiz raiz_arv. Retorna um ponteiro para o nó encontrado ou NULL
se o nó não existir*/
no* busca (no* raiz_arv,int chave){
	if(raiz_arv == NULL){
		return NULL;
	}
	else {
        if((raiz_arv->telefone)>chave){
		return busca(raiz_arv->esq,chave);
	}
	else if((raiz_arv->telefone)<chave){
		return busca(raiz_arv->dir,chave);
	}
	else{
        return raiz_arv;
	}
	}


}

/*função que tem como parâmetro os dados de um nó e o insere na arvore com raiz raiz_arv. O retorno é um ponteiro
para a raiz atualizada*/
no* insercao (int telefone,int rg,char *nome,char *email,no* raiz_arv){

	if(busca(raiz_arv,telefone)!=NULL){
		printf("elemento já existe.");
		return raiz_arv;
	}
	else{
		if(raiz_arv==NULL){
			raiz_arv = (no*)malloc(sizeof(no));
			raiz_arv->telefone = telefone; raiz_arv->rg = rg; raiz_arv->nome = nome;
			raiz_arv->email = email;
			raiz_arv->esq = raiz_arv->dir = NULL;
		}
		else if(raiz_arv->telefone>telefone){
			raiz_arv->esq = insercao(telefone,rg,nome,email,raiz_arv->esq);
			/*(raiz_arv->esq)->pai = raiz_arv;*/
		}
		else{
			raiz_arv->dir = insercao(telefone,rg,nome,email,raiz_arv->dir);
			/*(raiz_arv->dir)->pai = raiz_arv;*/
		}
		return raiz_arv;

	}

}

    void visitar(no *raiz)
{
if(raiz == NULL){
return;
}
printf("Telefone :%d\n",raiz->telefone);
printf("Nome: %s\n",raiz->nome);
printf("RG: %d\n",raiz->rg);
printf("Email: %s\n",raiz->email);
printf("<><><><><><><><><><><><><><>\n");
}

    void pre_ordem(no *raiz ){
     if(raiz !=NULL){
         visitar(raiz);
         pre_ordem(raiz->esq);
         pre_ordem(raiz->dir);
     }


    }





/*Estou com problemas em captar uma string. Por isso, o nome e o email se repete em todos os nós, mas a prova
que o programa funciona está nos campos telefone e rg.*/

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
    __fpurge(stdin);
    scanf("%d",&opt);

    switch(opt){
    case 1: ;
    int telefone,rg;
    char *nome,*email;
    printf("Novo telefone: ");
    __fpurge(stdin);
	scanf("%d",&telefone);
	printf("\nNome: ");
	__fpurge(stdin);
	scanf("%s",nome);
	printf("\nRG: ");
	__fpurge(stdin);
	scanf("%d",&rg);
	printf("\nEmail: ");
	__fpurge(stdin);
	scanf("%s",email);


    raiz= insercao(telefone,rg,nome,email,raiz);
    break;

    case 2:
        printf("Digite o numero de pesquisa: ");
        scanf("%d",&telefone);



    case 4:
        printf("Listando:\n");
        printf("Qual ordem vc deseja listar: \n");
        printf("[1]-Pre-ordem\n");
        printf("[2]-In-ordem\n");
        printf("[3]-Pos-ordem\n");
        int op;
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Listando em Pre-ordem:\n<><><><><><><><><><><><><><>\n");
                pre_ordem(raiz);
                break;
        }


    }


}


	return 0;

}

